#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int fib[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    fib[0] = fib[1] = 2;
    for (int i=2; i<=max(n, m); i++) {
        add(fib[i], fib[i-1]);
        add(fib[i], fib[i-2]);
    }

    int ret = fib[n];
    for (int i=0; i<m-1; i++)
        add(ret, fib[i]);

    cout << ret << "\n";

    return 0;
}