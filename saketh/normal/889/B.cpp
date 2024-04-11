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

    int N;
    cin >> N;

    vector<string> words(N);

    vector<bool> used(26);
    vector<int> succ(26, -1);
    vector<int> pred(26, -1);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        vector<bool> has(26);

        for (int j = 0; j < words[i].size(); j++) {
            int c = words[i][j] - 'a';

            if (has[c]) {
                cout << "NO\n";
                return 0;
            }

            has[c] = true;
            used[c] = true;

            if (j > 0) {
                int p = words[i][j-1] - 'a';
                if ((pred[c] != -1 && pred[c] != p) || (succ[p] != -1 && succ[p] != c)) {
                    cout << "NO\n";
                    return 0;
                }
                succ[p] = c;
                pred[c] = p;
            }
        }
    }

    vector<bool> hit(26);

    vector<string> tokens;
    for (int i = 0; i < 26; i++) {
        if (!used[i] || pred[i] != -1) continue;

        stringstream ss;
        hit[i] = true;
        ss << char('a' + i);
        for (int j = i; succ[j] != -1;) {
            j = succ[j];
            hit[j] = true;
            ss << char('a' + j);
        }
        tokens.push_back(ss.str());
    }

    for (int i = 0; i < 26; i++) {
        if (used[i] && !hit[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    sort(all(tokens));
    for (string str : tokens)
        cout << str;
    cout << endl;

    return 0;
}