#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n, a[N];
int h[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        rep(b, 0, 30) if(a[i] >> b & 1) h[i] = b;
    }
    int res = 0;
    rep(l, 0, n - 1) {
        ll csum = a[l + 1];
        int r = l + 2;
        while(r < n && csum < (1LL << (h[l] + 1))) {
            if(csum == (a[l] ^ a[r]) && a[l] >= a[r]) res++;
            csum += a[r];
            r++;
        }
    }
    for(int r = n - 1; r >= 1; r--) {
        ll csum = a[r - 1];
        int l = r - 2;
        while(l >= 0 && csum < (1LL << (h[r] + 1))) {
            if(csum == (a[l] ^ a[r]) && a[r] > a[l]) res++;
            csum += a[l];
            l--;
        }
    }
    cout << res << '\n';


}