#include <iostream>
#include <vector>
#define hw (y-x+1)/2
using namespace std;

const int MAXN = 300005;
const int SEGW = 1<<19;
const int MOD = 1000000007;
typedef long long ll;

struct node{
    ll a, b;
    node operator *(const int c) const{ return {(a*c)%MOD, (b*c)%MOD}; }
    node operator +(const node y) const{ return {(a+y.a)%MOD, (b+y.b)%MOD}; }
} seg[2*SEGW+5], lazy[2*SEGW+5];

int N, Q, P, dep[MAXN];
vector<int> chi[MAXN];
pair<int, int> seq[MAXN];

void prop(int, int, int);

node &upd(node v, int l, int r, int loc=1, int x=0, int y=SEGW-1){
    if(r<x || y<l) return seg[loc];
    if(l<=x && y<=r){
        if(x<y) lazy[loc] = lazy[loc] + v;
        return seg[loc] = seg[loc] + v * (y-x+1);
    }
    prop(loc, x, y);
    return seg[loc] = upd(v, l, r, 2*loc, x, x+hw-1) + upd(v, l, r, 2*loc+1, x+hw, y);
}

node que(int l, int r, int loc=1, int x=0, int y=SEGW-1){
    if(r<x || y<l) return {0, 0};
    if(l<=x && y<=r) return seg[loc];
    prop(loc, x, y);
    return que(l, r, 2*loc, x, x+hw-1) + que(l, r, 2*loc+1, x+hw, y);
}

void prop(int loc, int x, int y){
    if(lazy[loc].a==0 && lazy[loc].b==0) return;
    seg[loc] = upd(lazy[loc], x, x+hw-1, 2*loc, x, x+hw-1)
             + upd(lazy[loc], x+hw, y, 2*loc+1, x+hw, y);
    lazy[loc] = {0, 0}; 
}

int dfs(int loc = 0, int head = 0, int depth = 0){
    seq[loc].first = head++;
    dep[loc] = depth;
    for(int c : chi[loc]) head = dfs(c, head, depth+1);
    seq[loc].second = head-1;
    return head;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1; i<N; i++){
        cin >> P;
        chi[P-1].push_back(i);
    }
    dfs();

    cin >> Q;
    for(int i=0; i<Q; i++){
        ll T, V, X, K; cin >> T;
        if(T == 2){
            cin >> V; V--;
            node n = que(seq[V].first, seq[V].first);
            ll res = (n.a - n.b * dep[V]) % MOD;
            if(res < 0) res += MOD;
            cout << res << "\n";
        }
        else{
            cin >> V >> X >> K; V--;
            upd({(X+dep[V]*K)%MOD, K}, seq[V].first, seq[V].second);
        }
    }
    
    cout.flush();
    return 0;
}