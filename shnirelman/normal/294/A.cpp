#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >>  m;

    for(int i = 0; i<  m; i++) {
        int j, x;
        cin >> j >> x;

        j--;


        if(j <  n - 1)
            a[j + 1] += a[j] - x;
        if(j > 0)
            a[j - 1] += x - 1;
        a[j] = 0;

    }

    for(auto x : a)
        cout << x << endl;
}