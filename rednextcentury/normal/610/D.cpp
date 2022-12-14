#include <bits/stdc++.h>
using namespace std;
long long tree[1000000];
int a[1000000][4];
int n,N,M;
set<int> s1,s2;
map<int,int> X;
map<int,int> Y;
map<int,int> rX;
map<int,int> rY;
vector<pair<int,int> > H[1000000];
vector<pair<int,int> > V[1000000];
vector<pair<int,int> > tmp;
multiset<pair<int,pair<int,int> > > event;
long long sum=0;
void upd(int x,int l,int r,int v,int val)
{
    if (v<l || v>r)
        return;
    if (l==r && l==v)
        tree[x]+=val;
    else if (l!=r)
    {
        upd(x*2,l,(l+r)/2,v,val);
        upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
long long query(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    return query(x*2,l,(l+r)/2,s,e)+query(x*2+1,(l+r)/2+1,r,s,e);
}
void solve()
{
    for (int i=1;i<=N;i++)
    {
        while(event.size())
        {
            pair<int,pair<int,int> > p = *event.begin();
            if (p.first>i || p.second.first==1)
                break;
            event.erase(event.begin());
            upd(1,1,M,p.second.second,1);
        }
        for (int j=0;j<H[i].size();j++)
            sum-=query(1,1,M,H[i][j].first,H[i][j].second);
        while(event.size())
        {
            pair<int,pair<int,int> > p = *event.begin();
            if (p.first>i)
                break;
            event.erase(event.begin());
            upd(1,1,M,p.second.second,-1);
        }
    }

    cout<<sum<<endl;
}
void init()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3],s1.insert(a[i][0]),s1.insert(a[i][2]),s2.insert(a[i][1]),s2.insert(a[i][3]);
    N=1;
    while(s1.size())
    {
        rX[N]=*s1.begin();
        X[*s1.begin()]=N++;
        s1.erase(s1.begin());
    }
    N--;
    M=1;
    while(s2.size())
    {
        rY[M]=*s2.begin();
        Y[*s2.begin()]=M++;
        s2.erase(s2.begin());
    }
    M--;
    for (int i=0;i<n;i++)
    {
        int x1=X[a[i][0]];
        int y1=Y[a[i][1]];
        int x2=X[a[i][2]];
        int y2=Y[a[i][3]];
        if (x1==x2)
        {
            if (y1>y2)swap(y1,y2);
            H[x1].push_back(make_pair(y1,y2));
        }
        else
        {
            if (x1>x2)
                swap(x1,x2);
            V[y1].push_back(make_pair(x1,x2));
        }
    }
    for (int i=1;i<=N;i++)
    {
        sort(H[i].begin(),H[i].end());
        tmp.clear();
        for (int j=0;j<H[i].size();j++)
        {
            if (j==0)
                tmp.push_back(H[i][j]);
            else
            {
                if (H[i][j].first<=tmp[tmp.size()-1].second)
                    tmp[tmp.size()-1].second=max(tmp[tmp.size()-1].second,H[i][j].second);
                else
                    tmp.push_back(H[i][j]);
            }
        }

        for (int j=0;j<tmp.size();j++)
            sum+=rY[tmp[j].second]-rY[tmp[j].first]+1;
        swap(H[i],tmp);
    }
    for (int i=1;i<=M;i++)
    {
        sort(V[i].begin(),V[i].end());
        tmp.clear();
        for (int j=0;j<V[i].size();j++)
        {
            if (j==0)
                tmp.push_back(V[i][j]);
            else
            {
                if (V[i][j].first<=tmp[tmp.size()-1].second)
                    tmp[tmp.size()-1].second=max(tmp[tmp.size()-1].second,V[i][j].second);
                else
                    tmp.push_back(V[i][j]);
            }
        }
        for (int j=0;j<tmp.size();j++)
        {
            sum+=rX[tmp[j].second]-rX[tmp[j].first]+1;
            event.insert(make_pair(tmp[j].first,make_pair(0,i)));
            event.insert(make_pair(tmp[j].second,make_pair(1,i)));
        }
        swap(V[i],tmp);
    }
}
int main()
{
    init();
    solve();
}