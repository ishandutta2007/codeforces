#include<bits/stdc++.h>
#define MAXN 1000005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<1000001> bs;
int n,k;
int p[MAXN];
vector<int> v;
int c[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int now=i,cnt=0;
            do
            {
                vis[now]=true;
                now=p[now];
                cnt++;
            }while(!vis[now]);
            v.push_back(cnt);
            c[cnt]++;
        }
    }
    sort(v.begin(),v.end());
    int maxi=0,mini=0,ones=0,twos=0;
    for(int i=0;i<v.size();i++)
    {
        twos+=v[i]/2;
        ones+=v[i]%2;
    }
    int tmp=k;
    int x=min(tmp,twos); maxi+=2*x; twos-=x; tmp-=x;
    x=min(tmp,ones); maxi+=x;
    bs dp; dp.set(0);
    for(int i=1;i<=n;i++)
    {
        int removed=(c[i]-1)/2;
        c[2*i]+=removed;
        c[i]-=2*removed;
        while(c[i])
        {
            dp|=(dp<<i);
            c[i]--;
        }
    }   
    mini=(dp.test(k)?k:k+1);
    printf("%d %d\n",mini,maxi);
    return 0;
}