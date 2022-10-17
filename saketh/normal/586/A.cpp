#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
bool inp[128];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> inp[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (inp[i]) ans++;
        else if (i > 0 && inp[i-1] && i+1 < N && inp[i+1])
            ans++;
    }

    cout << ans << "\n";
}