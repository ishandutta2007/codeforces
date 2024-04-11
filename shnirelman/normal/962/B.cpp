#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int K = N * 30;
const int LOG = 30;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int lst = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            if(lst == -1) {
                if(a > b) {
                    a--;
                    lst = 0;
                    ans++;
                } else if(b > 0) {
                    b--;
                    lst = 1;
                    ans++;
                }
            } else if(lst == 0 && b > 0) {
                b--;
                lst = 1;
                ans++;
            } else if(lst == 1 && a > 0) {
                a--;
                lst = 0;
                ans++;
            } else {
                lst = -1;
            }

        } else {
            lst = -1;
        }
    }

    cout << ans << endl;
}