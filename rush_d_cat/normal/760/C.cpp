#include <iostream>
using namespace std;
typedef long long ll;
const int NICO = 200000 + 10;
int n;
int vis[NICO], b[NICO], p[NICO];
int main()
{
    cin >> n;int ok = 0, ans = 0;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> b[i], ok += b[i];
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans ++;int cur = i;
            while(!vis[p[cur]])
            {
                vis[p[cur]] = 1;
                cur = p[cur];
            }
        }
    }    
    if(ans == 1) ans = 0;
    if(ok%2 == 0) ans ++;
    cout << ans << endl;
}