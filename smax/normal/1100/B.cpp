#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    unordered_map<int, int> problems;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        if (problems.find(a) == problems.end())
            problems.insert(make_pair(a, 1));
        else
            problems[a]++;
        if (problems.size() == n) {
            cout << 1;
            for (int i=1; i<=n; i++) {
                problems[i]--;
                if (problems[i] == 0)
                    problems.erase(i);
            }
        } else
            cout << 0;
    }
    
    return 0;
}