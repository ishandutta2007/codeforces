#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<string> files(N);

    for (int i = 0; i < N; i++)
        cin >> files[i];

    vector<bool> del(N);

    int len = -1;

    for (int i = 0; i < M; i++) {
        int inx;
        cin >> inx;
        inx--;

        del[inx] = true;
        if (len != -1) {
            if (files[inx].length() != len) {
                cout << "No\n";
                return 0;
            }
        } else len = files[inx].length();
    }

    vector<char> pat(len, 0);

    for (int i = 0; i < N; i++) {
        if (!del[i]) continue;

        for (int j = 0; j < len; j++) {
            if (pat[j]) {
                if (pat[j] != '?' && pat[j] != files[i][j])
                    pat[j] = '?';
            } else pat[j] = files[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        bool match = false;

        if (files[i].length() == len) {
            match = true;
            for (int j = 0; j < len; j++)
                match &= (pat[j] == '?') || (pat[j] == files[i][j]);
        }

        if (del[i]) assert(match);
        else if (match) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (char c : pat)
        cout << c;
    cout << endl;

    return 0;
}