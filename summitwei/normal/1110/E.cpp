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

#define MN 100005
int n;
int c[MN];
int t[MN];
int dc[MN];
int dt[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        cin >> c[i];
    }
    FOR(i, 1, n){
        cin >> t[i];
    }

    if(c[1] != t[1] || c[n] != t[n]){
        cout << "No\n";
        return 0;
    }

    FOR(i, 1, n-1){
        dc[i] = c[i+1]-c[i];
        dt[i] = t[i+1]-t[i];
    }

    sort(dc+1, dc+n);
    sort(dt+1, dt+n);

    FOR(i, 1, n-1){
        //cout << dc[i] << " " << dt[i] << "\n";
        if(dc[i] != dt[i]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}