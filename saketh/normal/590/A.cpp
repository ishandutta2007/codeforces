#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 500;

int N;
int val[MAXN];
bool solid[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0 || i == (N - 1)) solid[i] = true;
        else {
            if (val[i-1] == val[i] || val[i] == val[i+1]) solid[i] = true;
            else solid[i] = false;
        }
    }

    int ans = 0;

    int streak = 0;
    for (int i = 0; i < N; i++) {
        if (!solid[i]) streak++;
        else {
            ans = max(ans, (streak + 1) / 2);
            streak = 0;
        }
    }

    cout << ans << "\n";

    int last;
    streak = 0;

    for (int i = 0; i < N; i++) {
        if (!solid[i]) streak++;
        else {
            if (streak > 0) {
                if (last == val[i]) {
                    for (int j = 0; j < streak; j++)
                        cout << val[i] << " ";
                } else {
                    for (int j = 0; j < streak / 2; j++) {
                        cout << last << " ";
                    }
                    for (int j = 0; j < streak / 2; j++) {
                        cout << val[i] << " ";
                    }
                }
            }

            cout << val[i] << " ";
            last = val[i];
            streak = 0;
        }
    }

    cout << "\n";
}