#include <bits/stdc++.h>
using namespace std;

int fib[50];
bool good[2000];

int main() {
    fill(good, good + 2000, false);
    fib[0] = fib[1] = 1;
    good[1] = true;
    for(int i = 2; i < 17; i++) fib[i] = fib[i-1] + fib[i-2], good[fib[i]] = true;

    int n;
    cin >> n;
    string res;
    for(int i = 1; i <= n; i++) res += (good[i] ? "O" : "o");
    cout << res;
}