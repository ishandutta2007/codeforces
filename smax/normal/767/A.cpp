#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    priority_queue<int> pq;
    cin >> n;
    int nextSize = n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        while (pq.top() == nextSize) {
            cout << pq.top() << " ";
            pq.pop();
            nextSize--;
        }
        cout << endl;
    }
    
    return 0;
}