#include <bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int a[1001001];
int S[1001001];
int E[1001001];
int L[1001001];
int R[1001001];
int LL[1001001];
int RR[1001001];
long long ret[1001001];
vector<pair<int,int> > vec[1001001];
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    int N=0;
    R[0]=-1;
    for (int i=1;i<=n;i++)
    {
        int l;
        scanf("%d",&l);
        L[i]=R[i-1]+1;
        R[i]=L[i]+l-1;
        for (int o=0;o<l;o++)
        {
            int x;
            scanf("%d",&x);
            a[N++]=x;
            vec[i].push_back({x,L[i]+o});
        }
        sort(vec[i].begin(),vec[i].end());
        reverse(vec[i].begin(),vec[i].end());
    }
    stack<int> st;
    for (int i=0;i<N;i++)
    {
        while(!st.empty() && a[st.top()]<a[i])
            st.pop();
        if (st.empty())
            S[i]=-1;
        else
            S[i]=st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    for (int i=N-1;i>=0;i--)
    {
        while(!st.empty() && a[st.top()]<a[i])
            st.pop();
        if (st.empty())
            E[i]=N;
        else
            E[i]=st.top();
        st.push(i);
    }
    for (int i=1;i<=n;i++)
    {
        int L1=1,R1=w-vec[i].size();
        int R2=w,L2=vec[i].size()+1;
        for (auto p:vec[i])
        {
            int loc = p.second-L[i]+1;
            LL[p.second] = (S[p.second]>=L[i])?max(loc,RR[S[p.second]]+1):loc;
            RR[p.second] = (E[p.second]<=R[i])?min(w-((int)vec[i].size()-(loc)),LL[E[p.second]]-1):w-(vec[i].size()-(loc));
            if (p.first<0)LL[p.second]=max(LL[p.second],R1+1),
                          RR[p.second]=min(RR[p.second],L2-1);
            if (LL[p.second]<=RR[p.second])
                ret[LL[p.second]]+=p.first,ret[RR[p.second]+1]-=p.first;
        }
    }
    for (int i=1;i<=w;i++)
        ret[i]+=ret[i-1],printf("%lld ",ret[i]);
}