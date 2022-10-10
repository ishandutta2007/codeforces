#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e7 + 1;
int sig[MAX], ans[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i < MAX; i++)
        for(int j = i; j < MAX; j += i)
            sig[j] += i;

    for(int i = MAX - 1; i >= 1; i--)
        if(sig[i] < MAX)
            ans[sig[i]] = i;

    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << (ans[x] ?: -1) << '\n';
    }
}