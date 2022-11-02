#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55
int n;
bool g[MN][MN];
int ps[MN][MN];
int aah[MN][MN][MN][MN];

int calc(int x1, int y1, int x2, int y2){
    if(aah[x1][y1][x2][y2] != -1) return aah[x1][y1][x2][y2];
    if(ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1] == 0){
        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << 0 << "\n";
        return 0;
    }

    int ans = max(x2-x1+1, y2-y1+1);
    FOR(i, x1, x2-1){
        ans = min(ans, calc(x1, y1, i, y2)+calc(i+1, y1, x2, y2));
    }
    FOR(i, y1, y2-1){
        ans = min(ans, calc(x1, y1, x2, i)+calc(x1, i+1, x2, y2));
    }
    aah[x1][y1][x2][y2] = ans;
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << ans << "\n";
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(aah, -1, sizeof aah);

    cin >> n;
    FOR(i, 1, n){
        FOR(j, 1, n){
            char c;
            cin >> c;
            if(c == '#') g[i][j] = true;
            ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+g[i][j];
            //cout << i << " " << j << " " << ps[i][j] << "\n";
        }
    }

    cout << calc(1, 1, n, n) << "\n";
    return 0;
}