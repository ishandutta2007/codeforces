#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
int rc[105], rw[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
        cin >> rc[i];

    for (int i = 0; i < M; i++)
        cin >> rw[i];

    sort(rc, rc+N);
    sort(rw, rw+M);

    int ans = -1;

    for (int t = 1; t <= 100; t++) {
        // all correct pass
        if (rc[N-1] > t) continue;

        // at least one passes with extra time
        if (2 * rc[0] > t) continue;

        // all incorrect fail
        if(rw[0] <= t) continue;

        ans = t;
        break;
    }

    cout << ans << endl;
}