#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L x*2
#define R x*2+1
vector<long long> mp;
map<long long,long long> to;
map<long long,long long> from;
struct node
{
    long long lE,rE,lF,rF;
};
node tree[4000000];
long long lazy[4000000];
void lzy(long long x,long long l,long long r)
{
    if (lazy[x]==1)
    {
        tree[x].lE=tree[x].rE=0;
        tree[x].lF=tree[x].rF=(r-l+1);

        lazy[L]=lazy[R]=1;
    }
    else if (lazy[x]==-1)
    {
        tree[x].lE=tree[x].rE=(r-l+1);
        tree[x].lF=tree[x].rF=0;

        lazy[L]=lazy[R]=-1;
    }
    else if (lazy[x]==-2)
    {
        swap(tree[x].lE,tree[x].lF);
        swap(tree[x].rE,tree[x].rF);

        if (lazy[L]==-1)
            lazy[L]=1;
        else if (lazy[L]==1)
            lazy[L]=-1;
        else if (lazy[L]==-2)
            lazy[L]=0;
        else lazy[L]=-2;

        if (lazy[R]==-1)
            lazy[R]=1;
        else if (lazy[R]==1)
            lazy[R]=-1;
        else if (lazy[R]==-2)
            lazy[R]=0;
        else lazy[R]=-2;
    }
    lazy[x]=0;
}
void build(long long x,long long l,long long r)
{
    tree[x].lE=(r-l+1),tree[x].rE=(r-l+1),tree[x].lF=0,tree[x].rF=0;
    if (l!=r)
    {
        build(L,l,mid);
        build(R,mid+1,r);
    }
}
void Upd(long long x,long long l,long long r,long long s,long long e,long long v)
{
    lzy(x,l,r);
    if (l>e || r<s)return;
    if (l>=s && r<=e)
    {
        lazy[x]=v;
        lzy(x,l,r);
    }
    else
    {
        Upd(L,l,mid,s,e,v);
        Upd(R,mid+1,r,s,e,v);
        if (tree[L].lE==(mid-l+1))
            tree[x].lE=tree[L].lE+tree[R].lE;
        else
            tree[x].lE=tree[L].lE;
        if (tree[R].rE==(r-mid))
            tree[x].rE=tree[R].rE+tree[L].rE;
        else
            tree[x].rE=tree[R].rE;

        if (tree[L].lF==(mid-l+1))
            tree[x].lF=tree[L].lF+tree[R].lF;
        else
            tree[x].lF=tree[L].lF;
        if (tree[R].rF==(r-mid))
            tree[x].rF=tree[R].rF+tree[L].rF;
        else
            tree[x].rF=tree[R].rF;
    }
}
long long A[1000000][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin>>q;
    mp.push_back(1);
    for (long long i=0;i<q;i++)
    {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
        mp.push_back(A[i][1]);
        mp.push_back(A[i][2]);
        mp.push_back(A[i][2]+1);
    }
    sort(mp.begin(),mp.end());
    from[mp[0]]=1;
    to[1]=mp[0];
    long long num=2;
    for (long long i=1;i<mp.size();i++)
    {
        if (mp[i]==mp[i-1])continue;
        from[mp[i]]=num++;
        to[num-1]=mp[i];
    }
    build(1,1,num);
    for (long long i=0;i<q;i++)
    {
        long long t=A[i][0],l=from[A[i][1]],r=from[A[i][2]];
        if (t==1)
            Upd(1,1,num,l,r,1);
        else if (t==2)
            Upd(1,1,num,l,r,-1);
        else
            Upd(1,1,num,l,r,-2);
        lzy(1,1,num);
        cout<<to[tree[1].lF+1]<<endl;
    }
}