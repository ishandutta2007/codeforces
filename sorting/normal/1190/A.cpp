#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

long long a[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;

    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }

    int j = 0, ans = 1;
    for(int i = 0; i < m; ++i){
        if((a[j] - j - 1) / k == (a[i] - j - 1) / k){
            continue;
        }
        j = i;
        ++ans;
    }

    cout << ans << "\n";

    return 0;
}