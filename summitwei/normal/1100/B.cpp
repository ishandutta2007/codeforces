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
int n, m;
//vi a[MN];

int cnt[MN];
int amt[MN]; //last time for each guy

int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //memset(amt, 0x3f, sizeof amt);

    cin >> n >> m;
    F0R(i, m){
        int x;
        cin >> x;
        cnt[x]++;
        //a[x].pb(i);
        amt[cnt[x]] = max(amt[cnt[x]], i);
    }

    int tim = m/n;
    //cout << tim << " ";

    //cout << "hmm\n";
    FOR(i, 1, n){
        //cout << amt[i] << " " << cnt[i] << "\n";
        //cout << cnt[i] << "\n";
        tim = min(tim, cnt[i]);
    }

    //cout << tim << "\n";

    FOR(i, 1, tim){
        ans[amt[i]] = 1;
    }

    //cout << "hmm\n";

    F0R(i, m){
        cout << ans[i];
    }

    return 0;
}