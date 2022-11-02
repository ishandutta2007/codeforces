#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 105
int t;
int n, k;
int a[MN];
map<int, int> in;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        in.clear();

        cin >> n >> k;
        F0R(i, n){
            cin >> a[i];
            in[a[i]] = 0;
        }
        if(in.size() > k){
            cout << "-1\n";
            continue;
        }
        int t = 0;
        //for(auto &u : in) u = t++;
        cout << n*k << "\n";
        F0R(i, n){
            for(auto u : in) cout << u.f << " ";
            F0R(_, k-in.size()) cout << "1 ";
        }
        cout << "\n";
    }
    
    return 0;
}