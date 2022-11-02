#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define NN 2000
ll x;
ll a, b, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x;
    a = 1+(x)/(NN-1);
    d = (NN-1)-(x%(NN-1));
    b = a+d;

    d = -d;

    cout << NN << "\n";
    F0R(i, NN-2){
        cout << "0 ";
    }
    cout << d << " "  << b << "\n";

    return 0;
}