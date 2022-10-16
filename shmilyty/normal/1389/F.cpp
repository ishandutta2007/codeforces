#include<bits/stdc++.h>
#define lk k<<1
#define rk k<<1|1
using namespace std;
const int N=2e5,M=(N<<1)+1,T=(M<<2);
int n,cnt,ans,l[N],r[N],t[N],b[M];
vector<int> ca[M];
struct Segtree{
	int mk[T],mx[T];
	void pushup(int k)
	{
		mx[k]=max(mx[lk],mx[rk]);
	}
    void pm(int k,int v)
	{
		mk[k]+=v;
		mx[k]+=v;
	}
    void pushdown(int k)
	{
		if(mk[k]) 
			pm(lk,mk[k]),
			pm(rk,mk[k]),
			mk[k]=0;
	}
    void fix(int x,int y,int v,int k,int l,int r)
	{
        if(x<=l&&r<=y) 
			return pm(k,v);
        pushdown(k);
        int mid=(l+r)>>1;
        if(mid>=x) 
			fix(x,y,v,lk,l,mid);
        if(mid<y) 
			fix(x,y,v,rk,mid+1,r);
        pushup(k);
    }
    int Mx()
	{
		return mx[1];
	}
    void Print(int k,int l,int r)
	{
        if(l==r)
		{
			cout<<mx[k]<<' ';
			return;
		}
        pushdown(k);
        int mid=(l+r)>>1;
        Print(lk,l,mid);
		Print(rk,mid+1,r);
    }
} g[2];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
		--t[i];
		b[cnt++]=l[i];
		b[cnt++]=r[i];
	}
	b[cnt++]=0;
	sort(b,b+cnt);
	cnt=unique(b,b+cnt)-b;
    for(int i=0;i<n;i++)
	{
        l[i]=lower_bound(b,b+cnt,l[i])-b;
        r[i]=lower_bound(b,b+cnt,r[i])-b;
        ca[r[i]].push_back(i);
    }
    for(int i=1;i<cnt;i++)
    {
    	for(int x:ca[i])
    		g[t[x]].fix(0,l[x]-1,1,1,0,cnt);
    	g[0].fix(i,i,g[1].Mx(),1,0,cnt);
    	g[1].fix(i,i,g[0].Mx(),1,0,cnt);
	}
	cout<<max(g[0].Mx(),g[1].Mx())<<endl;
	return 0;
}