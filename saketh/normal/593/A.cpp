#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string word[128];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> word[i];

    int ans = 0;

    for (char c1 = 'a'; c1 <= 'z'; c1++) {
        for (char c2 = c1 + 1; c2 <= 'z'; c2++) {
            int score = 0;
            for (int i = 0; i < N; i++) {
                bool incl = true;
                for (int j = 0; j < word[i].size(); j++) {
                    incl &= word[i][j] == c1 || word[i][j] == c2;
                }
                if (incl) score += word[i].size();
            }
            ans = max(ans, score);
        }
    }

    cout << ans << "\n";
}