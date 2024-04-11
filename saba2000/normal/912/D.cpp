#include<bits/stdc++.h>
#define pb push_back
#define F first
#define A second
using namespace std;
vector<int> x,y;
main()
{
    int n,m,r,k;
    cin>>n>>m>>r>>k;
    for (int i = 0; i < n; i++)
        x.pb(min(i , n - r) - max(0 , i - r + 1) + 1);
    for (int i = 0; i < m; i++)
        y.pb(min(i , m - r) - max(0 , i - r + 1) + 1);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        priority_queue <pair<int,pair<int,int> > > p;
    for (int i=0; i<x.size(); i++)
        p.push({x[i]*y[y.size()-1],{i,y.size()-1}});
    double ans=0;
    while(k--)
    {
        pair<int,pair<int,int> >  X=p.top();
        p.pop();
        ans+=X.F;
        if(X.A.A!=0)
            p.push({x[X.A.F]*y[X.A.A-1],{X.A.F,X.A.A-1}});
    }
    printf("%.9f",ans/(n-r+1)/(m-r+1));
}