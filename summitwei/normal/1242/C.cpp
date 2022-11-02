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
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 20
int k;
int n[MN];
vll a[MN];
ll bruh[MN];
ll sm;
map<ll, ll> ed;
map<ll, int> wtmoo;
int bleh[1<<MN];
vll ans[1<<MN];
bool check(int x){
    //cout << "doing " << x << "\n";
    if(bleh[x] != 0){
        //cout << "hey " << x << " okay\n";
        return (bleh[x] == 1);
    }
    int y = x;
    while(y > 0){
        if(y != x && check(y) && check(x ^ y)){
            //cout << "found " << x << " " << y << " " << (x^y) << "\n";
            bleh[x] = 1;
            for(auto u : ans[y]){
                ans[x].pb(u);
                //cout << "using " << u << "\n";
            }
            for(auto u : ans[x^y]){
                //cout << "using " << u << "\n";
                ans[x].pb(u);
            }
            return true;
        }
        y = (y-1)&x;
    }
    //cout << x << " bad. so sad\n";
    bleh[x] = 2;
    return false;
}
pair<ll, int> mv[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> k;
    F0R(i, k){
        cin >> n[i];
        F0R(_, n[i]){
            ll x;
            cin >> x;
            a[i].pb(x);
            sm += x; bruh[i] += x;
            wtmoo[x] = i;
        }
    }
    if(sm % k != 0){
        cout << "No\n";
        return 0;
    }
    ll ree = sm/k;
    //cout << ree << "\n";
    F0R(i, k){
        ll off = ree-bruh[i];
        F0R(j, n[i]){
            ll v = a[i][j];
            ed[v] = v+off;
            //cout << "connect " << v << " " << v+off << "\n";
        }
    }
    //cout << "hmm\n";
    F0R(i, k){
        F0R(j, n[i]){
            int bm = 0;
            ll cur = a[i][j];
            int v = i;
            //cout << "starting from " << cur << "\n";
            do{
                //cout << "on " << cur << "\n";
                if((1<<v) & bm){
                    break;
                }
                bm |= (1<<v);
                cur = ed[cur];
                if(!wtmoo.count(cur)){
                    break;
                }
                v = wtmoo[cur];
            } while(cur != a[i][j]);

            if(cur == a[i][j]){
                if(bleh[bm]) continue;
                ans[bm].pb(a[i][j]);
                bleh[bm] = true;
                //cout << "found result " << bm << " " << a[i][j] << "\n";
            }
        }
    }
    if(!check((1<<k)-1)){
        cout << "No\n";
        return 0;
    }
    for(auto u : ans[(1<<k)-1]){
        //cout << "extracting " << u << "\n";
        ll cur = u;
        int v = wtmoo[cur];
        do{
            ll nc = ed[cur];
            int nv = wtmoo[nc];
            mv[nv] = {nc, v};
            cur = nc; v = nv;
        } while(cur != u);
    }
    cout << "Yes\n";
    F0R(i, k){
        cout << mv[i].f << " " << mv[i].s+1 << "\n";
    }

    return 0;
}