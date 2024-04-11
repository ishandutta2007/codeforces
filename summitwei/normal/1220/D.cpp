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

#define MN 200005
int n;
int ls[MN];
ll b[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int oc = 0;
    F0R(i, n){
        cin >> b[i];
        int v = __builtin_ctzll(b[i]);
        ++ls[v];
    }
    int mx = 0;
    F0R(i, 64){
        if(ls[i] > ls[mx]){
            mx = i;
        }
    }
    cout << n-ls[mx] << "\n";
    F0R(i, n){
        int v = __builtin_ctzll(b[i]);
        if(v != mx){
            cout << b[i] << " ";
        }
    }

    return 0;
}