#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50, M = (int)3e6 + 50;

int n, num[N];
int cnt[M];
ll mul[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        cnt[num[i]] ++;
    }
    for(int i = 1; i < M; i++) {
        if(cnt[i] == 0) continue;
        for(int j = 1; i * j < M; j ++) {
            if(j == i) mul[i * j] += 1LL * cnt[i] * (cnt[j] - 1);
            else mul[i * j] += 1LL * cnt[i] * cnt[j];
        }
    }
    for(int i = 1; i < M; i++) mul[i] += mul[i-1];
    int q;
    cin >> q;
    while(q--) {
        int p; cin >> p;
        cout << 1LL * n * (n - 1) - mul[p - 1] << "\n";
    }
}