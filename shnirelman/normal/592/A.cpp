//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
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

    int n = 8;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int a = INF, b = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'W') {
                bool fl = false;
                for(int k = 0; k < i; k++)
                    fl |= (s[k][j] != '.');
                if(!fl)
                    a = min(a, i);
//                cout << "a " << fl << ' ' << i << endl;
            } else if(s[i][j] == 'B') {
                bool fl = false;
                for(int k = i + 1; k < n; k++)
                    fl |= (s[k][j] != '.');
                if(!fl)
                    b = min(b, n - i - 1);
//                cout << "b " << fl << ' ' << n - i - 1 << endl;
            }
        }
    }

    cout << (a <= b ? 'A' : 'B') << endl;
}