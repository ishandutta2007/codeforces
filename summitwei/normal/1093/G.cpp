#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
#define MK 5

//given array a of n points in k-dim space, dist = manhattan distance
//process q queries:
//1 i b1 b2... bk sets pt i to that pt
//2 l r finds max dist btwn two points in the indices
//k = 5 which is kind of nice, n = 2*10^5. time = 6s, memlim = 512 which is nice as well
//q = 2*10^5.
//every version of 2^k numbers makes 2^k segtrees of size 3*n
//this makes 32*6*10^5 = 2*10^7 roughly, which is actually probably okay

//so ye make these segtrees and each one is a maxtree? max of two opposites is correct,
//should be doable in o(q*logn*2^k) which is probably good enough.

int n, q, k;
int nums[MN][MK];
int orig[MN][1<<MK];
int tree[MN*3][1<<MK];

void getVals(int x){ //use bitmask magic to get the values. i don't think the time here rly matters
    F0R(i, 1<<MK){
        int val = 0;
        F0R(j, MK){
            if(i & 1<<j) val += nums[x][j];
            else val -= nums[x][j];
        }

        orig[x][i] = val;
    }
}

void build(int node, int a, int b, int type){
    if(a > b) return;

    if(a == b){
        tree[node][type] = orig[a][type];
        return;
    }

    build(node*2, a, (a+b)/2, type);
    build(node*2+1, 1+(a+b)/2, b, type);

    tree[node][type] = max(tree[node*2][type], tree[node*2+1][type]);
}

void upd(int node, int a, int b, int i, int j, int val, int type){
    if(a > j || b < i || a > b) return;

    if(a == b){
        tree[node][type] = val;

        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val, type);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val, type);

    tree[node][type] = max(tree[node*2][type], tree[node*2+1][type]);
}

int que(int node, int a, int b, int i, int j, int type){
    if(a > j || b < i || a > b){
        return -INF;
    }

    if(i <= a && b <= j){
        return tree[node][type];
    }

    int q1 = que(node*2, a, (a+b)/2, i, j, type);
    int q2 = que(node*2+1, 1+(a+b)/2, b, i, j, type);

    return max(q1, q2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(tree, -INF, sizeof tree);

    cin >> n >> k;
    //if k != 5 we pretend it equals five and dump a bunch of zeroes

    FOR(i, 1, n){
        F0R(j, k){
            cin >> nums[i][j];
        }

        getVals(i);
    }

    F0R(i, 1<<MK){
        build(1, 1, n, i);
    }

    cin >> q;
    F0R(_, q){
        int t;
        cin >> t;
        
        if(t == 1){
            int x;
            cin >> x;
            F0R(i, k){
                cin >> nums[x][i];
            }
            getVals(x);

            F0R(i, 1<<MK){
                upd(1, 1, n, x, x, orig[x][i], i);
            }
        } else{
            int l, r;
            cin >> l >> r;

            int mx = 0;
            F0R(i, 1<<(MK-1)){
                int one = que(1, 1, n, l, r, i);
                int two = que(1, 1, n, l, r, ((1<<MK)-1)-i);
                //cout << i << " " << (((1<<MK)-1)-i) << " ";
                //cout << one << " " << two << "\n";
                mx = max(mx, one+two);
            }

            cout << mx << "\n";
        }
    }

    return 0;
}