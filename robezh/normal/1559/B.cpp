#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 105;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        string str; int n;
        cin >> n;
        cin >> str;
        n = str.length();
        int fir = n;
        rep(i, 0, n) {
            if(str[i] != '?') {
                fir = i;
                break;
            }
        }
        int res = 0;
        rep(i, fir + 1, n) {
            if(str[i] == '?') {
                str[i] = (str[i - 1] == 'B' ? 'R' : 'B');
            }
        }
        for (int i = fir - 1; i >= 0; i--) {
            str[i] = (i == n - 1 || str[i + 1] == 'B' ? 'R' : 'B');
        }
        cout << str << endl;
    }

}