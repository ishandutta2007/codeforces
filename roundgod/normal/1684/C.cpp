#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<vector<int> > a;
bool sorted(vector<int> &v)
{
    for(int i=1;i<(int)v.size();i++) if(v[i-1]>v[i]) return false;
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        a.clear();
        a.resize(n);
        for(int i=0;i<n;i++)
        {
            a[i].resize(m);
            for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
        }
        P p=P(-1,-1);
        bool f=true;
        for(int i=0;i<n;i++)
        {
            int maxi=0,mini=INF+1,last=-1,fst=-1;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]>=maxi) {maxi=a[i][j]; continue;}
                else last=j;
            }
            for(int j=m-1;j>=0;j--)
            {
                if(a[i][j]<=mini) {mini=a[i][j]; continue;}
                else fst=j;
            }
            if(fst!=-1)
            {
                if(p.F==-1) p=P(fst,last);
                else if(p.F!=fst||p.S!=last) {f=false; break;}
            }
        }
        if(p.F!=-1)
        {
            for(int i=0;i<n;i++) 
            {
                swap(a[i][p.F],a[i][p.S]);
                if(!sorted(a[i])) f=false;
            }
        }
        if(!f) puts("-1");
        else if(p.F==-1) puts("1 1");
        else printf("%d %d\n",p.F+1,p.S+1);
    }
    return 0;
}