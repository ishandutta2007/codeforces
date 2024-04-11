#include <bits/stdc++.h>
using namespace std;

pair<int, int> problems[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> m;
    while (m--) {
        int n, t, a, b, easy = 0, hard = 0;
        cin >> n >> t >> a >> b;
        for (int i=0; i<n; i++) {
            cin >> problems[i].second;
            if (problems[i].second) hard++;
            else easy++;
        }
        for (int i=0; i<n; i++)
            cin >> problems[i].first;
        problems[n] = {t+1, 0};

        sort(problems, problems + n + 1);
        int ret = 0, timeRequired = 0, problemsRequired = 0;
        for (int i=0; i<=n; i++) {
            if (i == 0 || problems[i].first != problems[i-1].first) {
                int timeLeft = problems[i].first - 1 - timeRequired;
                if (timeLeft >= 0) {
                    int change = min(timeLeft / a, easy);
                    int extra = change;
                    timeLeft -= change * a;
                    change = min(timeLeft / b, hard);
                    extra += change;
                    ret = max(ret, problemsRequired + extra);
                }
            }
            timeRequired += (problems[i].second ? b : a);
            problemsRequired++;
            if (problems[i].second) hard--;
            else easy--;
            if (timeRequired > t)
                break;
        }

        cout << ret << "\n";
    }

    return 0;
}