#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a[300000] = {0};
    cin >> n >> m;
    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);
        
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;        
        set<int>::iterator it = alive.lower_bound(l);
        vector<int> toErase;        
        while(it != alive.end()){
            int cur = *it;            
            if(cur > r)
                break;                
            if(cur != x){    
                toErase.push_back(cur); a[cur] = x+1;
            }
            it++;
        }
 
        for (size_t j = 0; j < toErase.size(); j++)
            alive.erase(toErase[j]);
    }
    
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
 
    return 0;
}