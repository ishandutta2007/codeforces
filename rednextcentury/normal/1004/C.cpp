#include <bits/stdc++.h>
using namespace std;
long long LINF=(1LL<<55);
int INF=1e9;

set<pair<int,int> > S;
set<pair<int,int> > E;
int a[1000000];
int last[1000000];
int main()
{
    int n;
    cin>>n;
    memset(last,-1,sizeof(last));
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        if (last[x]==-1)
            S.insert(make_pair(i,x));
        last[x]=i;
    }
    for (int i=1;i<=n;i++)
    {
        E.insert(make_pair(last[a[i]],a[i]));
    }
    long long ret=0;
    while(!S.empty())
    {
        pair<int,int> p = *S.begin();
        S.erase(S.begin());
        while(!E.empty() && (*E.begin()).first<=p.first)
            E.erase(E.begin());
        ret+=E.size();
    }
    cout<<ret<<endl;
}