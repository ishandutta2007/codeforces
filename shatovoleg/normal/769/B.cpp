#include <cassert>
#include <iostream>
#include <map>
#include <deque>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

signed main()
{
    
    
    int n;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    
    auto cmp = [&mas] (int a, int b) {
        return mas[a] < mas[b];
    };
    
    multiset<int, decltype(cmp)> current(cmp);
    
    current.insert(0);
    
    multiset<int, decltype(cmp)> to_do(cmp);
    
    for (int i = 1; i < n; i++)
        to_do.insert(i);
    
    vector<pair<int, int>> ans;
    while (!to_do.empty()) {
        if (current.empty()) {
            cout << -1;
            exit(0);
        }
        
        int cur = *(current.rbegin());
        current.erase(--current.end());
        
        while (mas[cur] && to_do.size()) {
            ans.push_back({cur, *to_do.rbegin()});
            current.insert(*to_do.rbegin());
            to_do.erase(--to_do.end());
            mas[cur]--;
        }
        
        if (mas[cur]) {
            current.insert(cur);
        }
    }
    
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first + 1 << ' ' << it.second + 1 << endl;
    }
    
    return 0;
}