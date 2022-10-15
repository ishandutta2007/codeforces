#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int cnt=0;
        for(int i=0;i<n-1;i++) if(str[i]=='>') cnt++;
        int last=1;
        int tot=n;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]=='>')
            {
                int len=i+2-last;
                tot-=len;
                for(int j=last;j<=last+len-1;j++) a[j]=tot+(j-last+1);
                last=i+2;
            }
        }
        int len=n+1-last;
        tot-=len;
        for(int j=last;j<=last+len-1;j++) a[j]=tot+(j-last+1);
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
        tot=cnt+1;
        int id=cnt;
        a[1]=tot;
        for(int i=2;i<=n;i++)
        {
            if(str[i-2]=='>') a[i]=id--; else a[i]=++tot;
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
        
    }
    return 0;
}