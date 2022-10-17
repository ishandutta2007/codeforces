#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 500;

int N;
int kang[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> kang[i];

    sort(kang, kang + N);

    int ans = 0;
    int j = N / 2;

    for (int i = 0; i < N / 2; i++) {
        while (j < N && kang[j] < 2 * kang[i]) j++;
        if (j < N) {
            ans++;
            j++;
        }
    }

    cout << N - ans << "\n";
}