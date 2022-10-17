#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N;
int h[MAXN];
int s[MAXN];

unordered_map<int, int> imb;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h[i];
        s[i] = h[i];
    }

    sort(s, s + N);

    int blocks = 0;

    for (int i = 0; i < N; i++) {
        if (++imb[h[i]] == 0) {
            imb.erase(h[i]);
        }
        if (--imb[s[i]] == 0) {
            imb.erase(s[i]);
        }

        if (!imb.size())
            blocks++;
    }

    cout << blocks << "\n";
}