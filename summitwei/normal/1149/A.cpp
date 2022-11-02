#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
int a[MN];
int oc, tc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        if(a[i] == 1) ++oc;
        else ++tc;
    }

    if(oc >= 1 && tc >= 1){
        cout << "2 1 ";
        F0R(i, tc-1){
            cout << "2 ";
        }
        F0R(i, oc-1){
            cout << "1 ";
        }
    } else if(oc == 0){
        F0R(i, tc){
            cout << "2 ";
        }
    } else{
        F0R(i, oc){
            cout << "1 ";
        }
    }
    
    return 0;
}