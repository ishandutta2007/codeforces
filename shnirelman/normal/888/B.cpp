#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e7 + 13;
const int LOGN = 20;
const int A = 27;



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int lf = 0, rg = 0, up = 0, dw = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U')
            up++;
        else if(s[i] == 'D')
            dw++;
        else if(s[i] == 'R')
            rg++;
        else
            lf++;
    }

    cout << (min(lf, rg) + min(up, dw)) * 2 << endl;
}