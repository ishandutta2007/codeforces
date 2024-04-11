#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 105;

int n, k;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        if(k * 2 >= n) {
            cout << -1 << "\n";
            continue;
        }
        int l = 1, r = n;
        for(int i = 0; i < k; i++) {
            a[2 * i] = l++;
            a[2 * i + 1] = r--;
        }
        for(int i = 2 * k; i < n; i++) a[i] = r--;
        rep(i, 0, n) cout << a[i] << " ";
        cout << "\n";
    }

}