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

#define MN 100005
int n, k;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n >> k >> s;
        int z=0, o=0, idk=0;
        bool bad=false;
        F0R(i, k){
            bool sz=false, so=false;
            for(int j=i; j<=n; j+=k){
                if(s[j] == '0') sz=true;
                if(s[j] == '1') so=true;
            }
            if(sz && so){
                cout << "NO\n";
                bad=true;
                break;
            } else{
                if(sz) ++z;
                else if(so) ++o;
                else ++idk;
            }
        }
        if(bad) continue;
        if(z<o) swap(z, o);
        if(idk+o>=z){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}