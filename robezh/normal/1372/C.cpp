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

int n;
int p[N], la[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int cnt = 0;
        cin >> n;
        int last = -1;
        rep(i, 0, n) {
            cin >> p[i]; p[i]--;
            if(p[i] == i) {
                cnt++;
                last = i;
            }
            la[i] = last;
        }
        if(cnt == n) cout << 0 << "\n";
        else {
            bool found = false;
            rep(i, 0, n) {
                if(p[i] != i && i - la[i] == n - cnt) {
                    found = true;
                    break;
                }
            }
            cout << (found ? 1 : 2) << '\n';
        }
    }

}