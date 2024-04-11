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
int n, m, k;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;
    int mx = 0;
    int num = 0;
    F0R(i, n){
        cin >> a[i];
        if(a[i] > mx){
            mx = a[i];
            num = 1;
        } else if(a[i] == mx){
            num++;
        }
    }

    double ans = 0;
    ll sum = 0;
    int numDel = n;
    sort(a, a+n, greater<int>());
    F0R(i, n){
        numDel--;
        sum += a[i];
        if(numDel > m) continue;
        int nl = m-numDel;
        ll inc = min(1LL*nl, 1LL*(i+1)*k);

        ans = max(ans, (sum+inc)/(1.0+i));
    }

    cout << fixed << setprecision(8) << ans << "\n";
    
    return 0;
}