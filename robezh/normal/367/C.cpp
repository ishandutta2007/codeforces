#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

ll sum = 0;
int n, m;
int val[N];

int get(int x) {
    if(x % 2 == 1) return x * (x - 1) / 2;
    else {
        return x * (x - 1) / 2 + x / 2 - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a; cin >> a >> val[i];
    }
    sort(val + 1, val + m + 1, greater<int>());
    int cur = 1;

    while(cur <= m && get(cur) + 1 <= n) {
        sum += val[cur];
        cur++;
    }
    cout << sum << endl;
}