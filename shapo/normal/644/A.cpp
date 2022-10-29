#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector< vector< int > > res(a, vector< int > (b, 0));
    if (n > a * b) {
        cout << "-1" << endl;
    } else {
        for (int i = 0, cnt = 0; i < a; ++i) {
            if (b % 2 == 0 && i % 2) {
                for (int j = b - 1; j >= 0; --j) {
                    if (++cnt <= n) {
                        res[i][j] = cnt;
                    }
                }
            } else {
                for (int j = 0; j < b; ++j) {
                    if (++cnt <= n) {
                        res[i][j] = cnt;
                    }
                }
            }
        }
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}