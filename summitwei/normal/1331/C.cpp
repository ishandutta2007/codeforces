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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    bool a[6];
    F0R(i, 6){
        a[i] = (1<<(5-i))&n;
        //cout << a[i] << " ";
    }
    cout << a[0]*32+a[5]*16+a[3]*8+a[2]*4+a[4]*2+a[1] << "\n";
    
    return 0;
}