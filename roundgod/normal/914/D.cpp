#include<bits/stdc++.h>
#define MAXN 500030
using namespace std;
int n,q,a[MAXN],id[MAXN],savek;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
struct node
{
    int l,r,num;
}seg[4*MAXN];
void build(int k,int l,int r)
{
    seg[k].l=l;
    seg[k].r=r;
    if(l==r)
    {
        seg[k].num=a[l];
        id[l]=k;
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    seg[k].num=gcd(seg[k*2].num,seg[k*2+1].num);
}
void change(int l,int a)
{
	int k=id[l];
	seg[k].num=a;
	while(k>1)
	{
		k=k/2;
		seg[k].num=gcd(seg[k*2].num,seg[k*2+1].num);
	}
}
int query(int k,int l,int r,int x)
{
	 if(seg[k].l>r||seg[k].r<l) return 0;
	 if(seg[k].l>=l&&seg[k].r<=r)
	 {
	 	if(seg[k].num%x==0) return 0;
	 	else
	 	{
	 		savek=k;
	 		return 1;
	 	}
	 }
     int vl=query(k*2,l,r,x);
     int vr=query(k*2+1,l,r,x);
     return vl+vr;
}
bool query2(int k,int x)
{
	if(seg[k].l==seg[k].r) return true;
	bool vl=seg[k*2].num%x==0?true:false;
	bool vr=seg[k*2+1].num%x==0?true:false;
	if(!vl&&!vr) return false;
	else if(!vl) return query2(k*2,x);
	else if(!vr) return query2(k*2+1,x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
    	int t,l,r,x;
    	scanf("%d",&t);
    	if(t==1)
    	{
    		scanf("%d%d%d",&l,&r,&x);
    		int res=query(1,l,r,x);
    		if(res==0) {puts("YES"); continue;}
    		else if(res>1) {puts("NO"); continue;}
    		else {if(query2(savek,x)) puts("YES"); else puts("NO"); continue;}
    	}
    	else if(t==2)
    	{
    		scanf("%d%d",&l,&x);
    		change(l,x);
    	}
    }
    return 0;
}