#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_set<string> first_in;
    map<pair<string, int>, int> project_id;
    vector<pair<string, int>> project;
    vector<vector<pair<string, int>>> dependencies(n);
    vector<vector<int>> gr(n);
    vector<pair<string, int>> ans;

    for (int i = 0; i < n; i++) {
        string pname;
        int pver;
        cin >> pname >> pver;
        project_id[make_pair(pname, pver)] = i;
        project.push_back(make_pair(pname, pver));
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string depname;
            int depver;
            cin >> depname >> depver;
            dependencies[i].emplace_back(depname, depver);
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto dependency : dependencies[i]) {
            gr[i].push_back(project_id[dependency]);
        }
    }

    set<pair<pair<int, int>, int>> bfs;
    bfs.insert(make_pair(make_pair(0, 0), 0));
    while (!bfs.empty()) {
        auto x = *bfs.begin();
        bfs.erase(x);
        int pos = x.second;

        if (first_in.count(project[pos].first) == 0) {
            first_in.insert(project[pos].first);
            if (pos > 0) ans.push_back(project[pos]);
            for (auto j : gr[pos]) {
                bfs.insert(make_pair(make_pair(x.first.first + 1, -project[j].second), j));
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto elem : ans) {
        cout << elem.first << ' ' << elem.second << endl;
    }

    return 0;
}