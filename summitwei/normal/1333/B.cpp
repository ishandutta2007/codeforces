#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int t;
int n;
int a[MN]; ll b[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        bool hn = false, hp = false;
        FOR(i, 1, n){
            cin >> a[i];
        }
        bool ok = true;
        FOR(i, 1, n){
            cin >> b[i];
            if(b[i] < a[i]){
                if(!hn){
                    ok = false;
                }
            } else if(b[i] > a[i]){
                if(!hp){
                    ok = false;
                }
            }
            if(a[i] == 1) hp = true;
            if(a[i] == -1) hn = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}