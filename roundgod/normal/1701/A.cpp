#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            int x;
            scanf("%d",&x);
            cnt+=x;
        }
        if(cnt==0) puts("0"); else if(cnt==4) puts("2"); else puts("1"); 
    }
    return 0;
}