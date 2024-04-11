#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pi;
 
int main() {
    int n, m;
    bool bought[200000] = {false};
    pi arr[200000];
    priority_queue<pi, vector<pi>, greater<pi>> pq[3];
    
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        arr[i] = make_pair(p, i);
    }
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        pq[a-1].push(arr[i]);
    }
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        pq[b-1].push(arr[i]);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int c;
        cin >> c;
        while (!pq[c-1].empty() && bought[pq[c-1].top().second])
            pq[c-1].pop();
        if (pq[c-1].empty())
            cout << -1 << " ";
        else {
            bought[pq[c-1].top().second] = true;
            cout << pq[c-1].top().first << " ";
            pq[c-1].pop();
        }
    }
    
    return 0;
}