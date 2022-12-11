#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<string> team(n), homenames(n);
    for (int i = 0; i < n; ++i) {
        cin >> team[i] >> homenames[i];
    }
    auto firstOption = [&] (int i) {
        return team[i].substr(0, 3);
    };
    auto secondOption = [&] (int i) {
        return team[i].substr(0, 2) + homenames[i].substr(0, 1);
    };
    vector<string> possibleNames;
    for (int i = 0; i < n; ++i) {
        possibleNames.push_back(firstOption(i));
        possibleNames.push_back(secondOption(i));
    }
    sort(begin(possibleNames), end(possibleNames));
    possibleNames.erase(unique(begin(possibleNames), end(possibleNames)), end(possibleNames));
    auto comp = [&] (string s) {
        return distance(begin(possibleNames), lower_bound(begin(possibleNames), end(possibleNames), s));
    };
    vector<pair<int, int>> sids(n);
    for (int i = 0; i < n; ++i) sids[i] = {comp(secondOption(i)), comp(firstOption(i))};
    vector<int> startIn(possibleNames.size());
    for (int i = 0; i < n; ++i) startIn[sids[i].second]++;
    vector<bool> takeSecond(n);
    auto forceSecondOption = [&] (int i, auto self) {
        if (takeSecond[i]) return;
//        cout << i << " forced second\n";
        takeSecond[i] = true;
        for (int j = 0; j < n; ++j) {
            if (j == i || takeSecond[j]) continue;
            if (secondOption(i) == firstOption(j)) self(j, self);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (startIn[sids[i].second] > 1) forceSecondOption(i, forceSecondOption);
    }
    set<string> ansCheck;
    for (int i = 0; i < n; ++i) {
//        cout << i << " takes " << (takeSecond[i] ? secondOption(i) : firstOption(i));
        ansCheck.insert(takeSecond[i] ? secondOption(i) : firstOption(i));
    }
    if (ansCheck.size() < n) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << (takeSecond[i] ?secondOption(i) : firstOption(i)) << "\n";
    }
    return 0;
}