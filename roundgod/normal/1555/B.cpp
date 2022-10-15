#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
#define x1 dsakodas
#define y1 daksodsa
#define x2 dkaodsa
#define y2 cksodsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,W,H,x1,x2,y1,y2,w,h;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&W,&H);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d%d",&w,&h);
        if(w+(x2-x1)>W&&h+(y2-y1)>H) {puts("-1"); continue;}
        int width=(w+(x2-x1)>W?INF:max(0,min(w-x1,w-(W-x2))));
        int height=(h+(y2-y1)>H?INF:max(0,min(h-y1,h-(H-y2))));
        printf("%.10f\n",(double)min(width,height));
    }
    return 0;
}