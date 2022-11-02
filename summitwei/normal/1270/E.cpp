#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1005
int n;
pii a[MN];
vi ok;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i].f >> a[i].s;
        if((a[i].f+a[i].s) % 2 == 0){
            ok.pb(i);
        }
    }
    while(ok.size() == 0 || ok.size() == n){
        bool od = ok.size()==0;
        ok.clear();
        F0R(i, n){
            pii nw;
            if(od){
                nw = {(a[i].f-a[i].s+1)/2, (a[i].f+a[i].s+1)/2};
            } else{
                nw = {(a[i].f-a[i].s)/2, (a[i].f+a[i].s)/2};
            }
            a[i] = nw;
            //cout << a[i].f << " " << a[i].s << "\n";
            if((a[i].f+a[i].s) % 2 == 0){
                ok.pb(i);
            }
        }
    }
    
    cout << ok.size() << "\n";
    for(auto u : ok){
        cout << u+1 << " ";
    }

    return 0;
}