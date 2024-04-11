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

int a[N];
int s[N][10];

int main() {

    for(int i = 1; i < 10; i++)
        a[i] = i;

    for(int i = 10; i < N; i++) {
        int cur = 1;
        int x = i;
        while(x > 0) {
            if(x % 10 > 0)
                cur *= x % 10;
            x /= 10;
        }
        a[i] = a[cur];
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 10; j++)
            s[i][j] = s[i - 1][j];
        s[i][a[i]]++;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        cout << s[r][k] - s[l - 1][k] << '\n';
    }

}