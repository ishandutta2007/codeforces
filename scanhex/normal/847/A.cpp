#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }
    vector<vector<int>> lists;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
        if (!used[i] && l[i] == -1) {
            lists.push_back(vector<int> ());
            int j = i;
            while (j != -1) {
                lists.back().push_back(j);
                used[j] = true;
                j = r[j];
            }
        }
    }
    for (int i = 0; i < lists.size(); i++) {
        if (i != 0) {
            l[lists[i][0]] = lists[i - 1].back();
        }
        if (i + 1 < lists.size()) {
            r[lists[i].back()] = lists[i + 1][0];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << l[i] + 1 << " " << r[i] + 1 << endl;
    }

    return 0;
}