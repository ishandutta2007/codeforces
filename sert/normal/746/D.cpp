#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;


int main() {
    //init();
    int n, k, a, b, t;
    string s;
    cin >> n >> k >> a >> b;
    bool aa = (a > b);
    while (a + b > 0) {

        if (aa) {
            if (a == 0) {
                cout << "NO";
                return 0;
            }
            if (a <= b) {
                s.push_back('G');
                a--;
            } else {
                t = min(a, k);
                for (int i = 0; i < t; i++) s.push_back('G');
                a -= t;
            }
        } else {
            if (b == 0) {
                cout << "NO";
                return 0;
            }
            if (b <= a) {
                s.push_back('B');
                b--;
            } else {
                t = min(b, k);
                for (int i = 0; i < t; i++) s.push_back('B');
                b -= t;
            }
        }
        aa = !aa;
    }
    cout << s;
    return 0;
}