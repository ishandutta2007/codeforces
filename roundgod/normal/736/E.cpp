#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> v;
vector<P> vv;
char str[MAXN][MAXN];
int main()
{
    scanf("%d%d",&m,&n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
        sum+=x;
    }
    int need=m*(m-1);
    if(sum+v.back()*(m-n)*2<need) {puts("no"); return 0;}
    int cur=0;
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        cur+=2*m-2*(i+1);
        if(sum>cur)
        {
            puts("no");
            return 0;
        }
    }
    for(int i=n;i<m;i++)
    {
        cur+=2*m-2*(i+1);
        int x=min(cur-sum,v.back());
        v.push_back(x);
        sum+=x;
    }
    int tot=0;
    if(sum==need) puts("yes"); else {puts("no"); return 0;}
    for(auto p:v) vv.push_back(P(p,++tot));
    for(int i=1;i<=m;i++)
    {
        sort(vv.begin(),vv.end());
        int sz=(int)vv.size(),cur=2*sz-2,id=vv.back().S;
        int d=cur-vv.back().F;
        str[id][id]='X';
        for(int j=sz-2;j>=sz-1-d/2;j--)
        {
            int id2=vv[j].S;
            str[id][id2]='L';
            str[id2][id]='W';
            vv[j].F-=2;
        }
        int ed=sz-1-d/2-1;
        if(d&1)
        {
            int ind=d/2+1;
            int id2=vv[sz-1-ind].S;
            str[id][id2]=str[id2][id]='D';
            vv[sz-1-ind].F-=1;
            ed--;
        }
        for(int j=ed;j>=0;j--)
        {
            int id2=vv[j].S;
            str[id][id2]='W';
            str[id2][id]='L';
        }
        vv.pop_back();
    }
    for(int i=1;i<=m;i++) printf("%s\n",str[i]+1);
    return 0;
}