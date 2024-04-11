#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int solve() {
    int n; cin >> n;
    int cnt2 = 0, cnt3 = 0;
    while(n % 2 == 0) n /= 2, cnt2++;
    while(n % 3 == 0) n /= 3, cnt3++;
    if(n > 1 || cnt2 > cnt3) return -1;
    return cnt3 + (cnt3 - cnt2);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }

}