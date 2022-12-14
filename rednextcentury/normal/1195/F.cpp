#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
int L[1000000];
int R[1000000];
map<pair<int,int> ,int> last;
vector<pair<pair<int,int>,int> > Q;
int tree[4000000];
void upd(int x,int l,int r,int v,int val)
{
    if (v>r || v<l)return;
    if (l==r)tree[x]=val;
    else
    {
        if (v<=(l+r)/2)
            upd(x*2,l,(l+r)/2,v,val);
        else
            upd(x*2+1,(l+r)/2+1,r,v,val);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
int get(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return get(x*2,l,(l+r)/2,s,e)+get(x*2+1,(l+r)/2+1,r,s,e);
}
int ans[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    int cur=0;
    int tot=0;
    for (int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        L[i]=cur;
        R[i]=cur+k-1;
        cur+=k;
        vector<pair<int,int> > poly;
        for (int j=0;j<k;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            poly.push_back({x,y});
        }
        for (int j=0;j<k;j++)
        {
            int nxt = (j+1)%k;
            int x = poly[nxt].first - poly[j].first;
            int y = poly[nxt].second - poly[j].second;
            //if (x<0 && y<0)x=-x,y=-x;
            //if (y<0 && x>0)x=-x,y=-y;
            int G = __gcd(abs(x),abs(y));
            x/=G,y/=G;
            a[tot++]={x,y};
        }
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l=L[l-1];
        r=R[r-1];
        Q.push_back({{r,l},i});
    }
    sort(Q.begin(),Q.end());
    cur=0;
    for (auto p:Q)
    {

        int l = p.first.second,r=p.first.first,id=p.second;
        while(cur<=r){
            upd(1,0,tot,cur,1);
            if (last.find(a[cur])!=last.end())
                upd(1,0,tot,last[a[cur]],0);
            last[a[cur]]=cur;
            cur++;
        }
        ans[id]=get(1,0,tot,l,r);
    }
    for (int i=0;i<q;i++)
        printf("%d\n",ans[i]);
}