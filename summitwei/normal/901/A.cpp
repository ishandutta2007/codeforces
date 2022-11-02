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
#define MOD 998244353LL //119*2^23+1
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int h;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ok = false;
    cin >> h;
    F0R(i, h+1){
        cin >> a[i];
        if(a[i] > 1 && i != 0 && a[i-1] > 1){
            ok = true;
        }
    }
    if(!ok){
        cout << "perfect\n";
        return 0;
    }
    cout << "ambiguous\n";
    int cur = 0;
    F0R(i, h+1){
        F0R(_, a[i]) cout << cur << " ";
        cur = cur+a[i];
    }
    cout << "\n";
    cur = 0;
    F0R(i, h+1){
        if(i != 0 && a[i] > 1 && a[i-1] > 1){
            cout << cur-1 << " ";
            F0R(_, a[i]-1) cout << cur << " ";
        } else{
            F0R(_, a[i]) cout << cur << " ";
        }
        cur = cur+a[i];
    }
    cout << "\n";

    return 0;
}