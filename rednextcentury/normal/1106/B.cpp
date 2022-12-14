#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int c[1000000];
struct dish
{
    long long r;
    int c;
    int id;
} d[1000001];
int cur=1;
int id[1000000];
bool operator<(dish A,dish B)
{
    if (A.c == B.c) return A.id<B.id;
    else return A.c<B.c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i],d[i].r=a[i];
    for (int i=1;i<=n;i++)
        cin>>c[i],d[i].c=c[i],d[i].id=i;
    sort(d+1,d+n+1);
    for (int i=1;i<=n;i++)
        id[d[i].id]=i;
    while(m--)
    {
        long long t,D;
        cin>>t>>D;
        long long ret=0;
        t=id[t];
        if (D<=d[t].r)
        {
            d[t].r -= D;
            ret = D*d[t].c;
            cout<<ret<<endl;
        }
        else
        {
            D-=d[t].r;
            ret = d[t].r*d[t].c;
            d[t].r = 0;
            while(D && cur<=n)
            {
                if (d[cur].r==0)cur++;
                else
                {
                    if (D>d[cur].r)
                    {
                        D-=d[cur].r;
                        ret+=d[cur].r*d[cur].c;
                        d[cur].r=0;
                        cur++;
                    }
                    else
                    {
                        d[cur].r-=D;
                        ret+=D*d[cur].c;
                        D=0;
                    }
                }
            }
            if (D>0)ret=0;
            cout<<ret<<endl;
        }
    }
}