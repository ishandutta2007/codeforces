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
int n,q,curx,cury;
char s[2];
int main()
{
    scanf("%d",&n);
    curx=cury=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int x,y;
        scanf("%d%d",&x,&y);
        if(s[0]=='+')
        {
            if(curx==-1)
            {
                curx=x;
                cury=y;
            }
            else
            {
                ll sz1=1LL*max(curx,x)*max(cury,y);
                ll sz2=1LL*max(curx,y)*max(cury,x);
                if(sz1<=sz2) {curx=max(curx,x); cury=max(cury,y);}
                else {curx=max(curx,y); cury=max(cury,x);}
            }
        }
        else
        {
            if((x>=curx&&y>=cury)||(x>=cury&&y>=curx)) puts("YES"); else puts("NO");
        }
    }
    return 0;
}