#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 105;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        int si, sj, ti, tj;
        cin >> si >> sj >> ti >> tj;
        int t = min((si <= ti ? ti - si : (n - ti) + (n - si)), (sj <= tj ? tj - sj : (m - tj) + (m - sj)));
        cout << t << '\n';
    }


}