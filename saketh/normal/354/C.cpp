#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXV = 1e6 + 100;

int N, K;
int app[3*MAXV];
int pre[3*MAXV];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;
        app[V]++;
    }

    for (int i = 1; i < 3*MAXV; i++) {
        pre[i] = pre[i-1] + app[i];
    }

    int ans = 1;

    for (int g = 2; g <= MAXV; g++) {
        if(pre[g-1]) continue;

        bool ok = true;
        for (int b = g; b <= MAXV; b += g) {
            if(b+g-1 > b+K)
                ok &= (pre[b+g-1] - pre[b+K]) == 0; 
        }

        if(ok) ans = g;
    }

    cout << ans << endl;
}