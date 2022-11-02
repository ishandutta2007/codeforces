#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
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

#define MN 100005
ll n;
ll a[MN];
ll sm;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        sm += a[i];
    }
    sort(a, a+n);
    if(n == 1){
        if(a[0] % 2 == 1){
            cout << "sjfnb\n";
        } else{
            cout << "cslnb\n";
        }
        return 0;
    }
    bool eq = false;
    F0R(i, n-1){
        if(a[i] == a[i+1]){
            if(i != 0 && a[i-1] == a[i]-1){
                cout << "cslnb\n";
                return 0;
            } else if(a[i] == 0 || eq){
                cout << "cslnb\n";
                return 0;
            }
            eq = true;
        }
    }

    ll fin = n*(n-1)/2;
    ll steps = sm-fin;

    if(steps % 2 == 1){
        cout << "sjfnb\n";
    } else{
        cout << "cslnb\n";
    }

    return 0;
}