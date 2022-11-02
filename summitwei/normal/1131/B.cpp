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

#define MN 10005
int n;
int a[MN];
int b[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i] >> b[i];
    }

    int cnt = 0;
    FOR(i, 1, n){
        if(a[i-1] == a[i] && b[i-1] == b[i]) continue;
        if(a[i] == b[i]) cnt--;
        int mn = max(a[i-1], b[i-1]);
        int mx = min(a[i], b[i]);

        cnt += max((mx-mn+1), 0);
    }
    //if(a[n] == 0 && b[n] == 0) cnt++;
    if(a[n] == b[n]) cnt++;

    cout << cnt << "\n";

    return 0;
}