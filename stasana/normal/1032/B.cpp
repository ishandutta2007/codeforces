// Megumin

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 20; ++j) {
            if (i * j >= s.length()) {
                cout << i << " " << j << endl;
                int cnt = i * j - s.length();
                int ptr = 0;
                for (int q = 0; q < i; ++q) {
                    int w = 0;
                    if (cnt > 0) {
                        --cnt;
                        cout << "*";
                        ++w;
                    }
                    for (; w < j; ++w) {
                        cout << s[ptr];
                        ++ptr;
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }

    return 0;
}