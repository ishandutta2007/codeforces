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
int t;
int n;
int a[MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        int s=0;
        int m=0;
        FOR(i, 1, n){
            cin >> a[i];
            s += a[i];
            m = max(m, a[i]);
        }
        if(m+m > s){
            cout << "T\n";
        } else{
            if(s%2) cout << "T\n";
            else cout << "HL\n";
        }
    }

    return 0;
}