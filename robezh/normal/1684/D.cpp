#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = (int)2e5 + 50;

int a[N];
int n, k;
pii p[N];
int in[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 0, n) {
            cin >> a[i];
            p[i] = {-a[i] - i, i};
        }
        sort(p, p + n);
        fill(in, in + n, 0);
        rep(i, 0, k) {
            in[p[i].second] = 1;
//            cout << "in " << p[i].second << endl;
        }
        ll res = 0, tp = 0;
        rep(i, 0, n) {
            if(in[i]) tp++;
            else {
                res += tp + a[i];
            }
        }
        cout << res << '\n';
    }


}