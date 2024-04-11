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

#define MN 5005
#define MM 20005
int n, m;
pii c[MM];
int cnt[MN];
int lst[MN];

int dst(int x, int y){
    return (y+n-x)%n;
}

int ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    F0R(i, m){
        int a, b;
        cin >> a >> b;
        //st[c[i].f].pb(c[i].s);
        cnt[a]++;
        if(cnt[a] == 1) lst[a] = b;
        if(dst(a, lst[a]) > dst(a, b)){
            lst[a] = b;
        }
    }

    /*FOR(i, 1, n){
        cout << cnt[i] << " " << lst[i] << "\n";
    }*/

    FOR(i, 1, n){
        int mxt = 0;
        FOR(j, 1, n){
            if(cnt[j] == 0) continue;
            int gt = dst(i, j);
            int cyc = (max(cnt[j]-1, 0))*n;
            int nd = dst(j, lst[j]);
            mxt = max(mxt, gt+cyc+nd);
        }

        ans[i] = mxt;
    }

    FOR(i, 1, n){
        cout << ans[i] << " ";
    }

    return 0;
}