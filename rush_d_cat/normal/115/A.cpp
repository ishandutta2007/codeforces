#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int NICO = 2002;
int n, x;
int res = 0;
int used[NICO];
vector<int> vec[NICO];
void dfs(int x, int rank)
{
    used[x] = 1;
    int sz = vec[x].size();
    res = max(res, rank);
    for(int i=0;i<sz;i++)
    {
        if(!used[vec[x][i]])
        {
            dfs(vec[x][i], rank+1);
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> x;
        if(x==-1) vec[0].push_back(i);
        else
        {
            vec[x].push_back(i);
        }
    }
    dfs(0, 0);
    cout << res << endl;
}