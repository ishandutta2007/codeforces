#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> rem;
    vector<int> ans;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        rem.insert(i);
    stack<int> bnd;
    for(int i = 0; i < n; i++) {
        while(!bnd.empty() && *(rem.begin()) > bnd.top())
            bnd.pop();
        int x;
        if(i < k) {
            cin >> x;
            if(!bnd.empty() && x > bnd.top()) {
                cout << -1 << endl;
                return 0;
            }
        } else {
            int b;
            if(!bnd.empty())
                b = bnd.top();
            else
                b = n + 1;
            x = *(--rem.lower_bound(b));
        }
        //cout << "inserted " << x << endl;
        bnd.push(x);
        rem.erase(x);
        ans.push_back(x);
    }
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}