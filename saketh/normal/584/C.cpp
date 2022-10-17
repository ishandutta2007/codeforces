#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, T;
string a, b;

char ch(char c1, char c2) {
    char res = 'a';
    while(res == c1 || res == c2) res++;
    return res;
}

char ch(char c) { return ch(c, c); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> T >> a >> b;

    int same = 0, diff = 0;

    for (int i = 0; i < N; i++) {
        same += int(a[i] == b[i]);
        diff += int(a[i] != b[i]);
    }

    int wh = -1;

    for (int b = 0; b <= T; b++) {
        int rem = T - b;

        int used = 2 * rem;

        if (used <= diff && (b + used) >= diff && (b + used <= diff + same)) {
            wh = b;
            break;
        }
    }
    

    int ones = T - wh, done = 0;
    int difd = diff - 2 * ones;
    int difs = wh - difd;

    if (wh == -1 || difd < 0 || difs < 0)
    { cout << -1 << "\n"; return 0; }

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            if (difs > 0) {
                difs--;
                cout << ch(a[i]);
            }
            else cout << a[i];
        }
        else {
            if (difd > 0) {
                cout << ch(a[i], b[i]);
                difd--;
            } else {
                if (done < ones) cout << b[i];
                else cout << a[i];
                done++;
            }
        }
    }

    cout << "\n";
}