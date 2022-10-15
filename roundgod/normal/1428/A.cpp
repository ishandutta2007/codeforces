#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x1,y1,x2,y2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2||y1==y2) printf("%d\n",max(x1-x2,x2-x1)+max(y1-y2,y2-y1));
        else printf("%d\n",max(x1-x2,x2-x1)+max(y1-y2,y2-y1)+2);
    }
    return 0;
}