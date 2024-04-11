#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;



int main() {
    int n;
    cin >> n;

    for(int a = 0; a * 1234567 <= n; a++) {
        for(int b = 0; a * 1234567 + b * 123456 <= n; b++) {
            if((n - a * 1234567 - b * 123456) % 1234 == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}