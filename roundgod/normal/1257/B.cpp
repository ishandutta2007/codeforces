#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        if(x>=4) puts("YES");
        else if(x>1&&y<=3) puts("YES");
        else if(x==1&&y==1) puts("YES");
        else puts("NO");
    }
}