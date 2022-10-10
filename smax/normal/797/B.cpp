#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, sum = 0;
    priority_queue<int, vector<int>, greater<int>> pos, neg;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a > 0) {
            sum += a;
            if (a % 2 == 1)
                pos.push(a);
        } else if (a % 2 == -1)
            neg.push(-a);
    }
    
    if (sum % 2 == 0) {
        if (pos.empty())
            sum -= neg.top();
        else if (neg.empty())
            sum -= pos.top();
        else
            sum -= min(pos.top(), neg.top());
    }
    
    cout << sum << endl;
    
    return 0;
}