# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
multiset<long long> st;
pair<long long,long long> d1[1000000];
long long d2[1000000];
long long dist( long long x1,long long y1,long long x2,long long y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
    long long n,x1,y1,x2,y2;
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    for (long long i=0;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        d1[i]=make_pair(dist(x,y,x1,y1),i);
        d2[i]=dist(x,y,x2,y2);
        st.insert(d2[i]);
    }
    sort(d1,d1+n);
    long long r1=0,r2=*(--st.end());
    long long ans=r2;
    for (long long i=0;i<n;i++)
    {
        r1=d1[i].first;
        st.erase(st.find(d2[d1[i].second]));
        if (st.empty())
            r2=0;
        else
        r2=*(--st.end());
        ans=min(ans,r1+r2);
    }
    cout<<ans<<endl;
}