#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long inf = 1e9;

long long b[N], g[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;

    cin >> n >> m;

    long long mx = 0, mn = inf;

    for(long long i = 0; i < n; i++){
        cin >> b[i];
        mx = max(b[i], mx);
    }
    for(long long i = 0; i < m; i++){
        cin >> g[i];
        mn = min(g[i], mn);
    }

    if(mx > mn){
        cout << "-1\n";

        return 0;
    }

    long long sum = 0;
    bool ok = false;

    for(long long i = 0; i < n; i++){
        sum += b[i] * m;
    }

    for(long long j = 0; j < m; j++){
        sum -= mx;
        sum += g[j];
        if(g[j] == mx){
            ok = true;
        }
    }

    if(!ok){
        sum += mx;

        sort(b, b + n);

        sum -= b[n - 2];
    }

    cout << sum << "\n";

    return 0;
}