#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define clr(x,y) memset(x,y,sizeof x)
typedef long long ll;
const int maxn = 1000 + 10;
#define INF 0x3f3f3f3f
const ll Mod = 1e9 + 7;

int main()
{
    int Tcase;scanf("%d",&Tcase);
    while(Tcase --)
    {
        int n,k;scanf("%d%d",&n,&k);
        int ans = 1;int y = 0;
        if(k == 1)
        {
            int x;scanf("%d",&x);
            cout << max(x,n - x + 1) << endl;continue;
        }
        for(int i = 1;i <= k; i ++)
        {
            int x;scanf("%d",&x);
            if(i == 1){ans = max(ans,x);y = x;continue;}
            ans = max(ans,(x - y + 2)/2);
//            cout << x - y + 2 << endl;
            y = x;
        }
        ans = max(ans,n - y + 1);
        cout << ans << endl;
    }
    return 0;
}