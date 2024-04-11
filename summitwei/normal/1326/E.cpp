#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 1000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n;
int p[MN];
int q[MN];
int ip[MN];

struct Node{
    int nums=0, bmbs=0;
};
Node merge(Node a, Node b){ //nums of a and bmbs of b merge
    Node ans;
    int expl = min(a.nums, b.bmbs);
    ans.nums = a.nums+b.nums-expl;
    ans.bmbs = a.bmbs+b.bmbs-expl;
    return ans;
}
Node tree[4*MN];
void upd(int node, int a, int b, int i, int val){ //0=add num, 1=add bomb
    if(a > i || b < i) return;

    if(a == b){
        if(val == 0) tree[node].nums++;
        else tree[node].bmbs++;
        int expl = min(tree[node].nums, tree[node].bmbs);
        tree[node].nums -= expl; tree[node].bmbs -= expl;
        return;
    }
    upd(node*2, a, (a+b)/2, i, val);
    upd(node*2+1, 1+(a+b)/2, b, i, val);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> p[i];
        ip[p[i]] = i;
    }
    FOR(i, 1, n){
        cin >> q[i];
    }
    int ans = n;
    upd(1, 1, n, ip[n], 0);
    FOR(i, 1, n){
        while(tree[1].nums == 0){
            --ans;
            upd(1, 1, n, ip[ans], 0);
        }
        cout << ans << " ";
        upd(1, 1, n, q[i], 1);
    }
    cout << "\n";

    return 0;
}