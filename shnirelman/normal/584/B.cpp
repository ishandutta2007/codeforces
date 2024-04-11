#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 20;
const int A = 27;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;
    for(int a = 1; a <= 3; a++)
        for(int b = 1; b <= 3; b++)
            for(int c = 1; c <= 3; c++)
                cnt += (a + b + c == 6);

//    cout << cnt << endl;

    int x = 1, y = 1;
    for(int i = 0; i < n; i++) {
        x = x * 27ll % M;
        y = y * 1ll * cnt % M;
    }

    cout << (x + M - y) % M;
}