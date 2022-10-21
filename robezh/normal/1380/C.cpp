#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, x;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> x;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int cnt = 0, res = 0;
        for(int i = n - 1; i >= 0; i--) {
            cnt++;
            if(1LL * a[i] * cnt >= x) {
                res++;
                cnt = 0;
            }
        }
        cout << res << '\n';

    }


}