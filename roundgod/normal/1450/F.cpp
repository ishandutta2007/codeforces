#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) cnt[i]=0;
        int last=1;
        int s=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                s++;
                cnt[a[last]]++;
                cnt[a[i-1]]++;
                last=i;
            }
        }
        s++;
        cnt[a[last]]++;
        cnt[a[n]]++;
        int maxi=0,id=-1;;
        for(int i=1;i<=n;i++) 
        {
            if(cnt[i]>maxi)
            {
                maxi=cnt[i];
                id=i;
            }
        }
        if(maxi<=s+1) {printf("%d\n",s-1); continue;}
        int need=maxi-(s+1);
        int res=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]!=a[i-1]&&a[i]!=id&&a[i-1]!=id) res++;
        }
        if(res<need) puts("-1"); else printf("%d\n",s-1+need);
    }
}