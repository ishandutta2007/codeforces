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

#define MN 3005
int n;
ll a[MN];
ll dp[MN][MN];

vector<ll> stuff;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        a[i] -= i;

        //cout << a[i] << " ";

        stuff.pb(a[i]);
    }

    vector<ll>::iterator ree;
    sort(stuff.begin(), stuff.end());
    ree = unique(stuff.begin(), stuff.end());
    stuff.resize(distance(stuff.begin(), ree));

    int sz = stuff.size();

    F0R(i, sz){
        dp[0][i] = abs(a[0]-stuff[i]);
        if(i != 0) dp[0][i] = min(dp[0][i], dp[0][i-1]);
    }

    FOR(i, 1, n-1){
        F0R(j, sz){
            dp[i][j] = dp[i-1][j]+abs(a[i]-stuff[j]);
            if(j != 0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }

    /*cout << "\n";
    F0R(i, n){
        F0R(j, sz){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[n-1][sz-1];

    return 0;
}