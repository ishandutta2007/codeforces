#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3000005
int n, m;
pii a[MN];
int deg[MN];
set<int> e[MN];
vi res;
void eu(int cn){
    //cout << "vis " << cn << "\n";
    while(!e[cn].empty()){
        int nn = *e[cn].begin();
        e[nn].erase(cn);
        e[cn].erase(nn);
        eu(nn);
    }
    //cout << "done with " << cn << "\n";
    res.pb(cn);
}
int dsu[MN];
int fd(int x){
    if(dsu[x] < 0) return x;
    return dsu[x]=fd(dsu[x]);
}
bool jn(int x, int y){
    x = fd(x); y=fd(y);
    if(x == y) return false;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return true;
}

bool chk(int j){
    F0R(i, m+(1<<j)){
        //e[i].clear();
        dsu[i] = -1;
        deg[i] = 0;
    }
    //res.clear();
    F0R(i, n){
        int u = i*2, v=i*2+1;
        int x = a[i].f, y=a[i].s;
        x &= ((1<<j)-1); y &= ((1<<j)-1);
        //cout << i << " " << x << " " << y << "\n";
        //e[u].insert(v); e[v].insert(u);
        //e[u].insert(m+x); e[m+x].insert(u);
        //e[v].insert(m+y); e[m+y].insert(v);
        deg[u] += 2; deg[v] += 2; deg[m+x]++; deg[m+y]++;
        jn(u, v);
        jn(u, m+x);
        jn(v, m+y);
        //cout << u << " " << v << "\n";
        //cout << u << " " << m+x << "\n";
        //cout << v << " " << m+y << "\n";
    }
    int oct = 0;
    bool bad = false;
    F0R(i, m+(1<<j)){
        if(deg[i] % 2 != 0){
            bad = true;
            break;
        }
        if(deg[i] != 0 && dsu[i] < 0) ++oct;
    }
    if(bad || oct>1) return false;
    return true;
    //eu(0);
    //return res.size()==n*3+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i].f >> a[i].s;
    }
    m = 2*n;

    int l=0, r=21;
    while(l+1<r){
        int mid = (l+r)/2;
        if(chk(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    int j = l;
    F0R(i, m+(1<<20)) e[i].clear();
    res.clear();
    F0R(i, n){
        int u = i*2, v=i*2+1;
        int x = a[i].f, y=a[i].s;
        x &= ((1<<j)-1); y &= ((1<<j)-1);
        //cout << i << " " << x << " " << y << "\n";
        e[u].insert(v); e[v].insert(u);
        e[u].insert(m+x); e[m+x].insert(u);
        e[v].insert(m+y); e[m+y].insert(v);
        //cout << u << " " << v << "\n";
        //cout << u << " " << m+x << "\n";
        //cout << v << " " << m+y << "\n";
    }
    bool bad = false;
    F0R(i, m+(1<<20)){
        if(e[i].size() % 2 != 0){
            bad = true;
            break;
        }
    }
    assert(!bad);

    eu(0);
    res.pop_back();
    //cout << "tour:\n";
    //for(auto u : res) cout << u << " ";
    //cout << "\n";
    if(res.size() == n*3){
        //cout << "yay yay yay " << j << "\n";
        cout << j << "\n";
        vi ok;
        for(auto u : res){
            if(u<m) ok.pb(u);
        }
        if(ok[0]%2 == 1){
            if(ok[1] != ok[0]-1){
                int x = ok[0];
                ok.erase(ok.begin());
                ok.pb(x);
            }
        } else{
            if(ok[1] != ok[0]+1){
                int x = ok[0];
                ok.erase(ok.begin());
                ok.pb(x);
            }
        }
        for(auto u : ok) cout << u+1 << " ";
        cout << "\n";
        return 0;
    } else{
        assert(false);
    }

    return 0;
}