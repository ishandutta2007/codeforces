# include <bits/stdc++.h>
using namespace std;
struct trip
{
    int d;
    int v;
    int c;
};
int is[1000000];
bool operator<(trip& a, trip& b)
{
    return a.c<b.c;
}
bool operator<(const trip &a,const trip& b)
{
    return a.c<b.c;
}
bool comp(trip &a,trip &b)
{
    return a.d<b.d;
}
vector<trip> from,to;
multiset<trip> F[1000000],T[1000000];
trip a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
    {
        int d,f,t,c;
        cin>>d>>f>>t>>c;
        if (f==0)from.push_back(trip{d,t,c});
        else to.push_back(trip{d,f,c});
    }
    sort(from.begin(),from.end(),comp);
    sort(to.begin(),to.end(),comp);
    long long cost=0;
    for (int i=0;i<from.size();i++)
    {
        if (F[from[i].v].size())
        {
            trip mn=*F[from[i].v].begin();
            cost-=mn.c;
        }
        F[from[i].v].insert(from[i]);
        trip mn=*F[from[i].v].begin();
        cost+=mn.c;
    }
    int r=0;
    long long ret=((1LL)<<55);
    int num=0;
    for (int l=0;l<to.size();l++)
    {
        int st=to[l].d;
        int en=st+k+1;
        if (T[to[l].v].size()!=0)
        {
            trip mn=*T[to[l].v].begin();
            cost-=mn.c;
        }
        else
        {
            if (F[to[l].v].size())
                is[to[l].v]=1,num++;
        }
        T[to[l].v].insert(to[l]);
        trip mn=*T[to[l].v].begin();
        cost+=mn.c;
        while(r<from.size() && from[r].d<en)
        {
            trip MN=*F[from[r].v].begin();
            cost-=MN.c;
            F[from[r].v].erase(F[from[r].v].find(from[r]));
            if (F[from[r].v].size()==0)
            {
                num-=is[from[r].v];
                is[from[r].v]=0;
            }
            else
            {
                trip MN=*F[from[r].v].begin();
                cost+=MN.c;
            }
            r++;
        }
        if (num==n)
            ret=min(ret,cost);
    }
    if (ret==((1LL)<<55))
        ret=-1;
    cout<<ret<<endl;
}