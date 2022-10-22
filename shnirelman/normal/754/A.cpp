//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    if(s != 0) {
        cout << "YES" << endl << 1 << endl << 1 << ' ' << n << endl;
        return 0;
    }

    int s1 = 0;
    for(int i = 0; i < n; i++) {
        s1 += a[i];

        if(s1 != 0 && s1 + s != 0) {
            cout << "YES" << endl << 2 << endl << 1 << ' ' << i + 1 << endl << i + 2 << ' ' << n << endl;
            return 0;
        }
    }

    cout << "NO" << endl;


}