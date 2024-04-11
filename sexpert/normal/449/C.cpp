#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1e5 + 10;
int pr[MAX];
vector<int> guys[MAX];
vector<ii> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int p = 2; p <= n; p++) {
        if(pr[p]) {
            guys[pr[p]].push_back(p);
            continue;
        }
        guys[p].push_back(p);
        for(int q = p; q <= n; q += p)
            pr[q] = p;
    }
    for(int i = MAX - 1; i >= 3; i--) {
        if(guys[i].size() % 2) {
            if(guys[i].size() == 1)
                continue;
            ans.push_back({guys[i][0], guys[i][2]});
            for(int k = 3; k + 1 < guys[i].size(); k += 2)
                ans.push_back({guys[i][k], guys[i][k + 1]});
            guys[2].push_back(guys[i][1]);
        }
        else {
            for(int k = 0; k + 1 < guys[i].size(); k += 2)
                ans.push_back({guys[i][k], guys[i][k + 1]});
        }
    }
    if(guys[2].size() % 2)
        guys[2].pop_back();
    for(int k = 0; k + 1 < guys[2].size(); k += 2)
        ans.push_back({guys[2][k], guys[2][k + 1]});
    cout << ans.size() << '\n';
    for(auto p : ans)
        cout << p.first << " " << p.second << '\n';
}