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

bool is(vector<string> a) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++)
            if(a[i][j] == 'x' && a[i + 1][j] == 'x' && a[i + 2][j] == 'x')
                return true;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++)
            if(a[i][j] == 'x' && a[i][j + 1] == 'x' && a[i][j + 2] == 'x')
                return true;
    }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(a[i][j] == 'x' && a[i + 1][j + 1] == 'x' && a[i + 2][j + 2] == 'x')
                return true;

    for(int i = 0; i < 2; i++)
        for(int j = 2; j < 4; j++)
            if(a[i][j] == 'x' && a[i + 1][j - 1] == 'x' && a[i + 2][j - 2] == 'x')
                return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 4;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    bool ans = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '.') {
                a[i][j] = 'x';

                ans |= is(a);


                a[i][j] = '.';
            }
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}