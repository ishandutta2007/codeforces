#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, s[3000], c[3000];
    priority_queue<int, vector<int>, greater<int>> pq[3000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> s[i];
    for (int i=0; i<n; i++)
        cin >> c[i];
    
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (s[j] > s[i])
                pq[i].push(c[j]);
    
    int ret = INT_MAX;
    for (int i=0; i<n-2; i++)
        for (int j=i+1; j<n-1; j++)
            if (s[j] > s[i] && pq[j].size() > 0)
                ret = min(ret, c[i] + c[j] + pq[j].top());
    
    cout << (ret == INT_MAX ? -1 : ret) << endl;
    
    return 0;
}