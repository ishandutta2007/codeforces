#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,cnt[MAXN],ans,res;
string str;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(cnt[i]>=4) res++;
        ans+=cnt[i]/2;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        cin>>str;
        int x;
        scanf("%d",&x);
        ans-=cnt[x]/2;
        if(cnt[x]>=4) res--;
        if(str[0]=='-') cnt[x]--; else cnt[x]++;
        ans+=cnt[x]/2;
        if(cnt[x]>=4) res++;
        if(ans>=4&&res>=1) puts("YES"); else puts("NO");
    }
}