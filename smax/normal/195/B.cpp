#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, pair<double, int>> pi;
 
int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i=1; i<=m; i++)
        pq.push(make_pair(0, make_pair(abs((m + 1) / 2.0 - i), i)));
    for (int i=0; i<n; i++) {
        cout << pq.top().second.second << endl;
        pq.push(make_pair(pq.top().first + 1, make_pair(pq.top().second.first, pq.top().second.second)));
        pq.pop();
    }
    
    return 0;
}