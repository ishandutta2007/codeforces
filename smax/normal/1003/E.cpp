
// Problem : E. Tree Constructing
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, d, k;
    cin >> n >> d >> k;
    
    if (n == 1 || n - 1 < d || (k == 1 && n > 2)) {
        cout << "NO\n";
        return 0;
    }
    
    // make a chain
    vector<pair<int, int>> edges;
    for (int i=1; i<=d; i++)
        edges.emplace_back(i, i + 1);
    n -= d + 1;
    
    int id = d + 2;
    if (k > 2)
        for (int i=1; i<=d+1; i++) {
            if (n == 0)
                break;
            int canAdd = min(i - 1, d + 1 - i);
            if (canAdd == 0)
                continue;
            queue<pair<int, pair<int, int>>> q;
            q.push({i, {k-2, 0}});
            while (n > 0 && !q.empty()) {
                int u = q.front().first, dd = q.front().second.second;
                if (dd == canAdd)
                    break;
                if (--q.front().second.first == 0)
                    q.pop();
                
                edges.emplace_back(u, id);
                q.push({id++, {k-1, dd + 1}});
                n--;
            }
            /*for (int j=0; j<min(n, canAdd); j++) {
                edges.emplace_back(pred, id);
                pred = id++;
                amt++;
            }*/
        }
    
    /*int id = 1, maxDiameter = 0;
    pair<int, int> lowest{-1, 1};
    vector<int> maxed(n);
    vector<pair<int, int>> edges;
    queue<pair<int, pair<int, bool>>> q;
    q.push({-1, {0, false}});
    while (!q.empty() && n > d - maxDiameter) {
        int p = q.front().first, depth = q.front().second.first;
        bool expand = q.front().second.second;
        q.pop();
        
        if (expand) {
            maxDiameter++;
            if (maxDiameter > d) {
                cout << "NO\n";
                return 0;
            }
        }
        //cout << p << ", " << maxDiameter << "\n";
        
        maxed[depth]++;
        lowest = max(lowest, make_pair(depth, id));
        n--;
                
        if (p != -1)
            edges.emplace_back(p, id);
        
        for (int i=0; i<min(k-(id!=1), n); i++)
            q.push({id, {depth + 1, (i == 0 || (i == 1 && id == 1)) && maxed[depth] <= 2}});
        
        id++;
    }
    
    if (n < d - maxDiameter || (lowest.second != 1 && n > 0 && k == 1)) {
        cout << "NO\n";
        return 0;
    }*/
    
    if (n > 0) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    for (auto e : edges)
        cout << e.first << " " << e.second << "\n";
    /*while (d > maxDiameter) {
        cout << lowest.second << " " << lowest.second + 1 << "\n";
        lowest.second++;
        maxDiameter++;
    }*/

    return 0;
}