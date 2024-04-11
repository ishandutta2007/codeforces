#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL //119*2^23+1
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
struct Node{
    int nxt[2];
    int leaf = 0;
    int sz = 0;
    int p = -1;

    Node(int p=-1) : p(p){
        nxt[0] = -1; nxt[1] = -1;
    }
};
vector<Node> t(1);
void add(int x){
    int v = 0;
    RFOR(i, 29, 0){
        t[v].sz++;
        if(x & (1<<i)){
            if(t[v].nxt[1] == -1){
                t[v].nxt[1] = t.size();
                t.emplace_back(v);
            }
            v=t[v].nxt[1];
        } else{
            if(t[v].nxt[0] == -1){
                t[v].nxt[0] = t.size();
                t.emplace_back(v);
            }
            v=t[v].nxt[0];
        }
    }
    t[v].sz++;
}
int get(int x){
    int v = 0;
    int ans = 0;
    RFOR(i, 29, 0){
        t[v].sz--;
        if(x & (1<<i)){
            if(t[v].nxt[1] != -1 && t[t[v].nxt[1]].sz > 0){
                v = t[v].nxt[1];
                ans += 1<<i;
            } else{
                v = t[v].nxt[0];
            }
        } else{
            if(t[v].nxt[0] != -1 && t[t[v].nxt[0]].sz > 0){
                v = t[v].nxt[0];
            } else{
                v = t[v].nxt[1];
                ans += 1<<i;
            }
        }
    }
    t[v].sz--;
    return ans;
}

int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
    }
    F0R(i, n){
        int x;
        cin >> x;
        add(x);
    }
    F0R(i, n){
        int res = get(a[i]);
        cout << (a[i] ^ res) << " ";
    }

    return 0;
}