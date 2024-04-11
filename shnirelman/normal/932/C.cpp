//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*

*/

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int g = __gcd(a, b);

    if(n % g != 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i <= n / a; i++) {
        for(int j = 0; j <= (n - i * a) / b; j++) {
            if(i * a + j * b == n) {
                vector<int> res(n);
                for(int k = 0; k < i; k++) {
                    for(int l = k * a; l < (k + 1) * a - 1; l++)
                        res[l] = l + 1;
                    res[(k + 1) * a - 1] = k * a;
                }

                for(int k = 0; k < j; k++) {
                    for(int l = k * b + i * a; l < i * a + (k + 1) * b - 1; l++)
                        res[l] = l + 1;
                    res[i * a + (k + 1) * b - 1] = i * a + k * b;
                }

                for(auto x : res)
                    cout << x + 1 << ' ';
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
}