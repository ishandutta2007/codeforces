#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

int fact[300001];
pair<int, int> a[300000];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void add(int &a, int b) {
    a = (a + b) % MOD;
}

void sub(int &a, int b) {
    a = (a - b + MOD) % MOD;
}

void mul(int &a, int b) {
    a = (long long) a * b % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;

    fact[1] = 1;
    for (int i=2; i<=n; i++)
        fact[i] = (long long) fact[i-1] * i % MOD;

    sort(a, a + n);
    int numFirst = 1, numBoth = 1, runningLen = 1, num = -1, brunningLen = 1;
    pair<int, int> bnum = {-1, -1};
    for (int i=0; i<n; i++) {
        if (a[i].first == num)
            runningLen++;
        else {
            mul(numFirst, fact[runningLen]);
            num = a[i].first;
            runningLen = 1;
        }
        if (a[i] == bnum)
            brunningLen++;
        else if (a[i].second < bnum.second)
            numBoth = 0;
        else {
            mul(numBoth, fact[brunningLen]);
            bnum = a[i];
            brunningLen = 1;
        }
    }
    mul(numFirst, fact[runningLen]);
    mul(numBoth, fact[brunningLen]);

    sort(a, a + n, cmp);
    int numSecond = 1;
    runningLen = 1, num = -1;
    for (int i=0; i<n; i++) {
        if (a[i].second == num)
            runningLen++;
        else {
            mul(numSecond, fact[runningLen]);
            num = a[i].second;
            runningLen = 1;
        }
    }
    mul(numSecond, fact[runningLen]);

    sub(fact[n], numFirst);
    sub(fact[n], numSecond);
    add(fact[n], numBoth);
    cout << fact[n] << "\n";

    return 0;
}