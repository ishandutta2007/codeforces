#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define sz (1 << 18)
typedef long long ll;

int n, m;

struct NODE{
    int bitsum, lazy;
    NODE(){ bitsum = lazy = 0;}
};

NODE seg[21][sz * 2];

inline void lazy_eval(int pos, int k, int l, int r){
    if(seg[pos][k].lazy) seg[pos][k].bitsum = (r - l) - seg[pos][k].bitsum;
    if(k < sz){
	seg[pos][k * 2 + 1].lazy ^= seg[pos][k].lazy;
	seg[pos][k * 2 + 2].lazy ^= seg[pos][k].lazy;
    }
    seg[pos][k].lazy = 0;
}

inline void update_node(int pos, int k){ seg[pos][k].bitsum = seg[pos][k * 2 + 1].bitsum + seg[pos][k * 2 + 2].bitsum; }

void update(int pos, int a, int b, int k, int l, int r){
    lazy_eval(pos, k, l, r);
    if(b <= l || r <= a) return ;
    if(a <= l && r <= b){
	seg[pos][k].lazy ^= 1;
	lazy_eval(pos, k, l, r);
	return ;
    }
    update(pos, a, b, k * 2 + 1, l, (l + r) / 2);
    update(pos, a, b, k * 2 + 2, (l + r) / 2, r);
    update_node(pos, k);
}

int query(int pos, int a, int b, int k, int l, int r){
    lazy_eval(pos, k, l, r);
    if(b <= l || r <= a) return 0;
    if(a <= l && r <= b) return seg[pos][k].bitsum;

    int lch = query(pos, a, b, k * 2 + 1, l, (l + r) / 2);
    int rch = query(pos, a, b, k * 2 + 2, (l + r) / 2, r);
    update_node(pos, k);
    return lch + rch;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    rep(i, n){
	int a;
	cin >> a;
	rep(j, 20) if(a & (1 << j)) update(j, i, i + 1, 0, 0, n);
    }
    cin >> m;
    rep(i, m){
	int t, l, r, x;
	cin >> t;
	if(t & 1){
	    cin >> l >> r;
	    ll ans = 0;
	    rep(j, 20) ans += (ll)query(j, l - 1, r, 0, 0, n) * (1 << j);
	    cout << ans << endl;
	}else{
	    cin >> l >> r >> x;
	    rep(j, 20) if(x & (1 << j)) update(j, l - 1, r, 0, 0, n);
	}
    }
    return 0;
}