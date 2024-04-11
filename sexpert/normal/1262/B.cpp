#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 5;
int v[MAXN], ans[MAXN];
bool good;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        good = true;
        set<int> ab;
        for(int i = 1; i <= n; i++)
            ab.insert(i);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            if(v[i] < i)
                good = false;
            if(v[i] < v[i - 1])
                good = false;
            if(v[i] > v[i - 1]) {
                if(!ab.count(v[i]))
                    good = false;
                ans[i] = v[i];
                ab.erase(v[i]);
                continue;
            }
            ans[i] = *ab.begin();
            ab.erase(ab.begin());
        }
        if(!good)
            cout << "-1\n";
        else {
            for(int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << '\n';
        }
    }
}