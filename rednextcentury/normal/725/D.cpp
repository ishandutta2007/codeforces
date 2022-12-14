#include<bits/stdc++.h>
using namespace std;
multiset<pair<long long,long long> > s;
struct node
{
    long long t,w;
    int id;
};
bool operator<(node a,node b)
{
    if (a.t==b.t)
        return a.w<b.w;
    else
        return a.t>b.t;
}
node a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        scanf("%I64d%I64d",&a[i].t,&a[i].w),a[i].id=i;
    a[n].t=a[n].w=0;
    a[n].id=n;
    n++;
    int num=0;
    for (int i=1;i<n;i++)
    {
        if (a[i].t>a[0].t)num++;
    }
    int ans=num;
    num=0;
    sort(a+1,a+n);
    int i=1;
    for (;i<n;i++)
    {
        if (a[i].t>a[0].t)
            s.insert(make_pair(a[i].w-a[i].t+1,a[i].t)),num++;
        else
        {
            while(s.size() && (a[0].t-s.begin()->first)>=a[i].t)
                a[0].t-=s.begin()->first,s.erase(s.begin()),num--;
            ans=min(ans,num);
            if (!s.size())
                break;
            if (a[0].t-s.begin()->first>=0)
                a[0].t-=s.begin()->first,s.erase(s.begin()),s.insert(make_pair(a[i].w-a[i].t+1,a[i].t));
        }
    }
    cout<<ans+1<<endl;
}