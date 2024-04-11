#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b,c;
string str;
int ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        cin>>str;
        int cnt=0;
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            if(str[i]=='R'&&b)
            {
                b--; ans[i]=1;
                cnt++;
            }
            else if(str[i]=='P'&&c)
            {
                c--; ans[i]=2;
                cnt++;
            }
            else if(str[i]=='S'&&a)
            {
                a--; ans[i]=0;
                cnt++;
            }
        }
        if(cnt*2<n) puts("NO");
        else
        {
            puts("YES");
            for(int i=0;i<n;i++)
                if(ans[i]==-1)
                {
                    if(a) {a--; ans[i]=0;}
                    else if(b) {b--; ans[i]=1;}
                    else {c--; ans[i]=2;}
                }
            for(int i=0;i<n;i++) printf("%c",!ans[i]?'R':(ans[i]==1?'P':'S'));
            puts("");
        }
    }
    return 0;
}