#include <iostream>
#include <set>
using namespace std;

set<int> st[200005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        st[u].insert(v);
        st[v].insert(u);
    }
    int d = 0;
    bool b[200005]{0};
    for(int u = 0; u < n; u++){
        if(!st[u].empty() && *st[u].rbegin() > u){
            b[u] = true;
            d++;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int u, v;
            cin >> u >> v;
            u--; v--;
            d -= b[u];
            d -= b[v];
            st[u].insert(v);
            st[v].insert(u);
            if(!st[u].empty() && *st[u].rbegin() > u){
                b[u] = true;
                d++;
            }
            else b[u] = false;
            if(!st[v].empty() && *st[v].rbegin() > v){
                b[v] = true;
                d++;
            }
            else b[v] = false;
        }
        if(t == 2){
            int u, v;
            cin >> u >> v;
            u--; v--;
            d -= b[u];
            d -= b[v];
            st[u].erase(v);
            st[v].erase(u);
            if(!st[u].empty() && *st[u].rbegin() > u){
                b[u] = true;
                d++;
            }
            else b[u] = false;
            if(!st[v].empty() && *st[v].rbegin() > v){
                b[v] = true;
                d++;
            }
            else b[v] = false;
        }
        if(t == 3) cout << n - d << endl;
    }
}