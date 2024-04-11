#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2000 + 13;
const int K = 30;
const int M = 1e9 + 7;
const int LOGN = 20;

void solve() {
    string s;
    cin >> s;

    int sum = 0;
    for(char c : s)
        sum += c - 'a' + 1;

    int a = (s.size() % 2 == 0 ? sum : sum - min(s[0] - 'a' + 1, s.back() - 'a' + 1));
    int b = sum - a;

    if(a > b)
        cout << "Alice " << a - b << endl;
    else
        cout << "Bob " << b - a << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}