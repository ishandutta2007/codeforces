/*

1dfs
set
a) set<=1,

b) set=2
  
    i  ~
    ii)  root

c)set>2

*/
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
const int NICO = 200000 + 10;
vector<int> vec[NICO];
int n, u, v, root;
int dfs(int x, int par)
{
    set<int> st;
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(cur == par) continue;
        int t=dfs(cur, x);
        if(t == -1) return -1;
        st.insert(t+1);
    }
    if(st.size() == 0) return 0;
    if(st.size() == 1) return *st.begin();
    if(st.size() == 2 && par == 0) return *st.rbegin() + *st.begin();
    if(st.size() > 2) return -1;
    root = x;
    return -1;
}
int main()
{
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int ans = dfs(1, 0);
    if(ans == -1 && root) ans = dfs(root, 0);
    while(ans%2==0)
    {
        ans /= 2;
    }
    cout << ans << endl;
}