#include <bits/stdc++.h>
using namespace std;

vector<int> ret;
unordered_set<int> visited, exited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, numEvents = 0;
    bool solExists = true;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        numEvents++;
        if (a > 0) {
            if (visited.count(a))
                solExists = false;
            visited.insert(a);
        } else {
            if (!visited.count(-a) || exited.count(a))
                solExists = false;
            exited.insert(a);
            if (visited.size() == exited.size()) {
                ret.push_back(numEvents);
                numEvents = 0;
                visited.clear();
                exited.clear();
            }
        }
    }

    if (numEvents > 0) {
        if (visited.size() != exited.size())
            solExists = false;
        ret.push_back(numEvents);
    }

    if (solExists) {
        cout << ret.size() << "\n";
        for (int i : ret)
            cout << i << " ";
        cout << "\n";
    } else
        cout << "-1\n";

    return 0;
}