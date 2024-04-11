#include<bits/stdc++.h>
using namespace std;
#define R x*2
#define L x*2+1
#define mid (l+r)/2
int a[4000000];
int tree[4000000];
char s[1200002];
void upd(int x,int l,int r,int v)
{
    if (v<l || v>r)
        return;
    else if (l==r)
        tree[x]=a[r];
    else
    {
        upd(R,l,mid,v);
        upd(L,mid+1,r,v);
        tree[x]=tree[R]+tree[L];
    }
}
int sum(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    else
        return sum(R,l,mid,s,e)+sum(L,mid+1,r,s,e);
}
struct query
{
    int s;
    int e;
    int id;
} q[1000001];
vector<int> interval[2000001];
stack<int> st;
bool operator<(query A,query B)
{
    return A.e<B.e;
}
int ans[2000000];
int main()
{
    scanf("%s",&s);
    int n=strlen(s);
    for (int i=0;i<n;i++)
    {
        if (s[i]=='(')
            st.push(i);
        else
        {
            if (!st.empty())
            {
                interval[i].push_back(st.top());
                st.pop();
            }
        }
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].s,&q[i].e);
        q[i].s--,q[i].e--;
        q[i].id=i;
    }
    sort(q,q+m);
    int added=0;
    for (int i=0;i<m;i++)
    {
        while(added<=q[i].e)
        {
            for (int j=0;j<interval[added].size();j++)
                a[interval[added][j]]++,upd(1,0,n-1,interval[added][j]);
            added++;
        }
        ans[q[i].id]=sum(1,0,n-1,q[i].s,q[i].e);
    }
    for (int i=0;i<m;i++)
        printf("%d\n",ans[i]*2);
}