#include <bits/stdc++.h>
using namespace std;

#define LEN 317

int power[100000], nxt[100000], cnt[100000], last[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> power[i];

    for (int i=n-1; i>=0; i--) {
        int step = 0, j = i;
        while (j < n && i / LEN == j / LEN) {
            step++;
            j += power[j];
        }
        nxt[i] = (j < n ? j : -1);
        cnt[i] = step;
        last[i] = (i + power[i] < n ? last[i+power[i]] : i);
    }

    while (m--) {
        int type, a;
        cin >> type >> a;
        a--;
        if (type == 0) {
            int b;
            cin >> b;
            power[a] = b;
            for (int i=a; i>=a/LEN*LEN; i--) {
                int newI = i + power[i];
                if (newI >= n) {
                    nxt[i] = -1;
                    cnt[i] = 1;
                    last[i] = i;
                } else if (i / LEN == newI / LEN) {
                    nxt[i] = nxt[newI];
                    cnt[i] = cnt[newI] + 1;
                    last[i] = last[newI];
                } else {
                    nxt[i] = newI;
                    cnt[i] = 1;
                    last[i] = last[newI];
                }
            }
        } else {
            int step = 0;
            while (nxt[a] != -1) {
                step += cnt[a];
                a = nxt[a];
            }
            step += cnt[a];
            cout << last[a]+1 << " " << step << "\n";
        }
    }

    return 0;
}