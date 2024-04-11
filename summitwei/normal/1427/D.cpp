#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55 //check limits you incompetent ree
int n;
int c[MN];
int d[MN];
void swp(vi x){
    int a=1;
    int b=n;
    RFOR(i, x.size()-1, 0){
        b -= x[i];
        FOR(j, b+1, b+x[i]){
            d[a] = c[j];
            ++a;
        }
    }
    FOR(i, 1, n) c[i] = d[i];
}
vector<vi> aah;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> c[i];
    bool b4 = false;
    int l = find(c+1,c+n+1,1)-c;
    int r = l;
    FOR(i, 1, n-1){
        int loc = find(c+1, c+n+1, i+1)-c;
        vi res;
        //cout << l << " " << r << " " << loc << " " << b4 << "\nc: ";
        //FOR(j, 1, n) cout << c[j] << " ";
        //cout << "\n";
        if(loc<l){
            if(loc != 1) res.pb(loc-1);
            res.pb(l-loc);
            if(b4){
                res.pb(1);
                res.pb(i-1);
            } else{
                res.pb(i);
            }
            if(n != r) res.pb(n-r);
            
            b4 = false;
        } else{
            if(l != 1) res.pb(l-1);
            if(b4){
                res.pb(1);
                res.pb(i-1);
            } else{
                res.pb(i);
            }
            res.pb(loc-r);
            if(n != loc) res.pb(n-loc);
            
            b4 = true;
        }
        swp(res);
        aah.pb(res);
        l = min(find(c+1, c+n+1, 1)-c, find(c+1, c+n+1, i+1)-c);
        r = max(find(c+1, c+n+1, i)-c, find(c+1, c+n+1, i+1)-c);
    }
    if(b4){
        vi res;
        res.pb(1);
        res.pb(n-1);
        swp(res);
        aah.pb(res);
    }
    cout << aah.size() << "\n";
    for(auto u : aah){
        cout << u.size() << " ";
        for(auto v : u) cout << v << " ";
        cout << "\n";
    }

    return 0;
}