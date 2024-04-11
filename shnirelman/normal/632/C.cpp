#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 5e5 + 13;
const int INF = 2e9;

mt19937 rnd(time(0));

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i <n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < n; i++)
        cout << a[i];
}