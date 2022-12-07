#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
typedef long long ll;
int N;
ll p[MAXN], s[MAXN], a[MAXN], ans;
const ll INF = 12345678901234567;
vector<int> children[MAXN];
bool flag;
void dfs(int node)
{
    if(s[node] == -1)
        {
            s[node] = INF;
            for(int j=0; j<children[node].size(); j++)
            {
                s[node] = min(s[node], s[children[node][j]]);
            }
            if(s[node] < s[p[node]])
            {
                cout<<-1<<endl;
                flag = true;
            }
            else if(children[node].size())
            {
                ans += (s[node] - s[p[node]]);
            }
        }
        else
        {
            ans += (s[node]-s[p[node]]);
        }
    for(int i=0; i<children[node].size(); i++)
    {
        dfs(children[node][i]);
    }
}
int main()
{
    cin>>N;
    for(int i=2; i<=N; i++)
    {
        cin>>p[i];
        children[p[i]].push_back(i);
    }
    for(int i=1; i<=N; i++)
    {
        cin>>s[i];
    }
    dfs(1);
    if(!flag)
    cout<<ans<<endl;
}