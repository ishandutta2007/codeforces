#include<bits/stdc++.h>
#define MAXN 100005
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
        if((x+y)&1) {puts("-1 -1"); continue;}
        if(x>=y) printf("%d %d\n",(x+y)/2,0);
        else printf("%d %d\n",x,(x+y)/2-x);
    }
    return 0;
}