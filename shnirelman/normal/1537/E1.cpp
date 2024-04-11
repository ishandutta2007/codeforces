#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;



int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string mn = "";
    for(int i = 0; i < k; i++)
        mn += s[0];
    string t = "";
    for(int i = 0; i < n; i++) {
        t += s[i];
        string r = "";
        for(int j = 0; j < k; j++)
            r += t[j % t.size()];
        mn = min(mn, r);
    }

    cout <<mn << endl;



}