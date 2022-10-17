#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;

int N;
int vals[MAXN];
int len[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        len[i] = 1;
        if(i>0 && vals[i] >= vals[i-1]) len[i] += len[i-1];
        ans = max(ans, len[i]);
    }

    cout << ans << endl;
}