#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int NICO = 100000 + 10;
int n, vis[NICO];
vector<int> v, ans, v2, tmp;
void getPrime()
{   
    for(int i=2;i<=n/2;i++)
    {
        if(!vis[i])
        {
            v.push_back(i);
            for(int j=2*i;j<=n;j+=i)
            {
                vis[j] = 1;
            }
        }
    }
}   
int main()
{
    cin >> n;
    getPrime();
    memset(vis, 0, sizeof(vis));
    for(int i=v.size()-1;i>=0;i--)
    {
        tmp.clear();
        for(int j=1;j*v[i]<=n;j++)
        {
            if(!vis[j*v[i]]) vis[j*v[i]] = 1, tmp.push_back(j*v[i]);
        }
        int odd = tmp.size() % 2;
        for(int j=0;j<tmp.size();j++)
        {
            if(odd&&j==1) 
            {
                vis[tmp[j]] = 0;
                continue;
            }
            ans.push_back(tmp[j]);
        }
    }
    printf("%d\n", (int)ans.size()/2);
    for(int i=0;i+1<ans.size();i+=2)
    {
        printf("%d %d\n", ans[i], ans[i+1]);
    }
}