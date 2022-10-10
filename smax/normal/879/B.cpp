#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, mx = 0;
    long long k;
    queue<int> q;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        q.push(a);
        mx = max(mx, a);
    }
    if (k >= n - 1) {
        cout << mx << endl;
        return 0;
    }
    int acc, curChamp = -1;
    while (true) {
        int p = q.front();
        q.pop();
        if (p > curChamp) {
            q.push(curChamp);
            acc = curChamp == -1 ? 0 : 1;
            curChamp = p;
        } else {
            q.push(p);
            acc++;
            if (acc == k) {
                cout << curChamp << endl;
                return 0;
            }
        }
    }
    
    return 0;
}