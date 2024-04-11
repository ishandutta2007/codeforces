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

#define MN 305
int t;
int n, m;
int gr[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        bool ok = true;
        F0R(i, n){
            F0R(j, m){
                cin >> gr[i][j];
                int amt=2;
                if(i!=0&&i!=n-1) amt++;
                if(j!=0&&j!=m-1) amt++;
                if(gr[i][j] > amt) ok=false;
                else gr[i][j] = amt;
            }
        }
        if(!ok){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            F0R(i, n){
                F0R(j, m){
                    cout << gr[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}