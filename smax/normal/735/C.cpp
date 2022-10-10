#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    vector<long long> fib = {1, 2};
    while (fib[fib.size()-1] <= n)
        fib.push_back(fib[fib.size()-2] + fib[fib.size()-1]);

    cout << fib.size() - 2 << "\n";

    return 0;
}