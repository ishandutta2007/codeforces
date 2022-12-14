#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[2000001];
struct Base
{
	#define type int
	#define mx 20
	type d[mx+1];
	type p[mx+1];
	int sz;
	int cnt;
	Base()
	{
        sz=0;
        cnt=0;
        for (int i=0;i<=mx;i++)
            d[i]=p[i]=0;
	}
	Base(int x)
	{
	    sz=0;
        cnt=0;
        for (int i=0;i<=mx;i++)
            d[i]=p[i]=0;
	}
	bool insert(type x)
	{
		int i;
		for(i=mx;~i;i--)
		{
			if(!(x&(1LL<<i))) continue;
			if(!d[i])
			{
				cnt++;
				d[i]=x;
				break;
			}
			x^=d[i];
		}
		if (x)
            p[sz++]=x;
		return x>0;
	}
	type query_max()
	{
		int i;
		type res=0;
		for(i=mx;~i;i--)
		{
			if ((res^d[i]) > res)res^=d[i];
		}
		return res;
	}
	type query_min()
	{
		for(int i=0;i<=mx;i++)
		{
			if(d[i]) return d[i];
		}
		return 0;
	}
};
Base Merge(Base A,Base B)
{
    if (A.sz==0)return B;
    if (B.sz==0)return A;
    Base C = A;
    for(int i=0;i<B.sz;i++)
    {
        int x = B.p[i];
        C.insert(x);
    }
	return C;
}
int ret[1000000];
Base cur[1000000];
int L[1000000];
int R[1000000];
void dc(vector<int>& vec,int l,int r)
{
    if (vec.size()==0)return;
    int mid=(l+r)/2;
    Base tmp = Base(0);
    for (int i=mid-1;i>=l;i--)
    {
        tmp.insert(a[i]);
        cur[i]=tmp;
    }
    tmp = Base(0);
    for (int i=mid+1;i<=r;i++)
    {
        tmp.insert(a[i]);
        cur[i]=tmp;
    }
    vector<int> Q1,Q2;
    for (auto i:vec)
    {
        if (R[i]<mid)
            Q1.push_back(i);
        else if (L[i]>mid)
            Q2.push_back(i);
        else
        {
            Base rr=Base(0);
            rr.insert(a[mid]);
            if (L[i]<mid)rr=Merge(rr,cur[L[i]]);
            if (R[i]>mid)rr=Merge(rr,cur[R[i]]);
            ret[i]=rr.query_max();
        }
    }
    dc(Q1,l,mid);
    dc(Q2,mid+1,r);
}
vector<int> Q;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
        scanf("%d%d",&L[i],&R[i]);
        Q.push_back(i);
    }
    dc(Q,1,n);
    for (int i=0;i<q;i++)
        printf("%d\n",ret[i]);
}