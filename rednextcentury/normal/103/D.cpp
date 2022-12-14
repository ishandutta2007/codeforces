#include<bits/stdc++.h>
using namespace std;
long long dp[1000000];
long long a[1000000];
struct node
{
    int a;
    int b;
    int id;
};
bool operator<(node a,node b)
{
    return a.b<b.b;
}
node q[1000000];
long long ret[1000000];
int SQRT=600;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].a,&q[i].b);
        q[i].a--;
        q[i].id=i;
    }
    sort(q,q+m);
    int last=-1;
    for (int i=0;i<m;i++)
    {
        if (q[i].b>SQRT)
            for (int j=q[i].a;j<n;j+=q[i].b)
                ret[q[i].id]+=a[j];
        else
        {
            if (q[i].b==last)
                ret[q[i].id]=dp[q[i].a];
            else
            {
                for (int j=n-1;j>=0;j--)
                {
                    if (j+q[i].b>n-1)
                        dp[j]=a[j];
                    else
                        dp[j]=a[j]+dp[j+q[i].b];
                }
                ret[q[i].id]=dp[q[i].a];
                last=q[i].b;
            }
        }
    }
    for (int i=0;i<m;i++)
        printf("%I64d\n",ret[i]);
}