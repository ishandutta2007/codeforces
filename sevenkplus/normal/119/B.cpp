#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,m,w,a[1000];bool v[1000];
vector<double> p;vector<int> q;
int main()
{
    scanf("%d%d",&n,&k),m=n/k;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&w);
    for(int i=1;i<=w;i++)
    {
        int x=0;vector<int> r;
        for(int j=1;j<=m;j++)
        {
            int y;
            scanf("%d",&y);v[y]=1,x+=a[y];
        }
        p.push_back((x+0.0)/m);
    }
    for(int i=1;i<=n;i++)if(!v[i])q.push_back(a[i]);
    sort(q.begin(),q.end());
    if((int)q.size()+k*m!=n)
    {
        int x=0;
        for(int i=0;i<m;i++)x+=q[i];
        p.push_back((x+0.0)/m);
        x=0;
        reverse(q.begin(),q.end());
        for(int i=0;i<m;i++)x+=q[i];
        p.push_back((x+0.0)/m);
    }
    sort(p.begin(),p.end());
    printf("%.9lf %.9lf\n",*p.begin(),*p.rbegin());
    return 0;
}