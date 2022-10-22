#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0;i < n; i++) {
        int x;
        cin >> x;

        bool fl = false;
        for(int a = 0; a < 100 && !fl; a++) {
            for(int b = 0; b < 100 && !fl; b++) {
                if(a * 3 + b * 7 == x) {
                    cout << "YES" << endl;
                    fl = true;
                }
            }
        }

        if(!fl) {
            cout << "NO" << endl;
        }
    }
}