#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10;

#define LC(id) (2 * id)
#define RC(id) (2 * id + 1)

int mx[4 * maxn], mn[4 * maxn], lz[4 * maxn];

void shift(int l, int r, int id){
    mx[id]+= lz[id];
    mn[id]+= lz[id];
    if(r-l > 1){
	lz[LC(id)]+= lz[id];
	lz[RC(id)]+= lz[id];
    }
    lz[id] = 0;
}
int fnd(int x, int l = 0, int r = maxn, int id = 1){
    shift(l, r, id);
    if(mx[id] <= x)
	return l;
    int mid = (l+r) >> 1;
    if(mn[LC(id)] + lz[LC(id)] <= x)
	return fnd(x, l, mid, LC(id));
    return fnd(x, mid, r, RC(id));
}
void add(int f, int s, int x, int l = 0, int r = maxn, int id = 1){
    shift(l, r, id);
    if(s <= l || r <= f)
	return;
    if(f <= l && r <= s){
	lz[id]+= x;
	shift(l, r, id);
	return;
    }
    int mid = (l+r) >> 1;
    add(f, s, x, l, mid, 2*id);
    add(f, s, x, mid, r, 2*id+1);
    mn[id] = min(mn[LC(id)], mn[RC(id)]);
    mx[id] = max(mx[LC(id)], mx[RC(id)]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0, sum = 0;
    int lst = 0;
    for(int i = 0; i < n; i++){
	if(s[i] == '0'){
	    lst = i+1;
	    ans+= sum;
	}
	else{
	    int pos = fnd(i-lst);
	    add(pos, i+1, 1);
	    sum+= i+1-pos;
	    ans+= sum;
	}
    }
    return cout << ans << endl, 0;
}