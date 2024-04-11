#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int need[1024];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> need[i];
    }

    int got = 0, loc = 0, dir = 1, ans = 0;

    while (true) {
        if (need[loc] <= got) {
            need[loc] = 1e9;
            got++;

            if(got == N) break;
        }

        if (loc + dir < 0 || loc + dir == N) {
            dir *= -1;
            ans++;
        }

        loc += dir;
    }

    cout << ans << "\n";
}