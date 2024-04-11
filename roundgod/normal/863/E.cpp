#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n;
int l[MAXN],r[MAXN],a[2*MAXN],res[MAXN*2];
int mp[MAXN*2];
map<int,int> mymap;
int main()
{
    scanf("%d",&n);
    int t=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        r[i]++;
        mp[t++]=l[i];
        mp[t++]=r[i];
    }
    sort(mp,mp+t);
    int cnt=1;
    mymap[mp[0]]=0;
    for(int i=1;i<t;i++)
    {
        if(mp[i]==mp[i-1]) continue;
        else
        {
            mymap[mp[i]]=cnt;
            cnt++;
        }
    }
    for(int i=0;i<n;i++)
    {
        l[i]=mymap[l[i]];
        r[i]=mymap[r[i]]-1;
    }
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        a[l[i]]++;
        a[r[i]+1]--;
    }
    for(int i=1;i<2*MAXN;i++)
        a[i]+=a[i-1];
    res[0]=(a[0]==1?1:0);
    for(int i=1;i<2*MAXN;i++)
        res[i]=res[i-1]+(a[i]==1?1:0);
    bool f=false;
    t=-1;
    for(int i=0;i<n;i++)
    {
        if(l[i]==0)
        {
            if(res[r[i]]==0)
            {
                f=true;
                t=i+1;
                break;
            }
        }
        else if(res[r[i]]==res[l[i]-1])
        {
            f=true;
            t=i+1;
            break;
        }
    }
    if(f) printf("%d\n",t); else puts("-1");
    return 0;
}