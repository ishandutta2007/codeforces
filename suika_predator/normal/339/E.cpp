#include<iostream>
#include<cstdio>
using namespace std;
struct seg
{
	int l,r,rev;
}x[23],t[23];
int top;
int n,a[2333];
inline void reverse(int l,int r)
{
	for(int i=l;i<=r;i++)t[i].rev^=1;
	while(l<r)swap(t[l],t[r]),l++,r--;
}
bool chk()
{
//	cout<<"chk"<<endl;
	for(int i=1;i<=top;i++)t[i]=x[i];
	int last=0;
	for(int i=1;i<=top;i++)
	{
		if(t[i].l!=last+1||(t[i].rev!=0&&t[i].l!=t[i].r))
			return false;
		last=t[i].r;
	}
	printf("0\n");
	return true;
}
bool chk(int l1,int r1)
{
//	cout<<"chk "<<l1<<' '<<r1<<endl;
	for(int i=1;i<=top;i++)t[i]=x[i];
	reverse(l1,r1);
//	for(int i=1;i<=top;i++)cout<<i<<' '<<t[i].l<<' '<<t[i].r<<' '<<t[i].rev<<endl;
	int last=0;
	for(int i=1;i<=top;i++)
	{
		if(t[i].l!=last+1||(t[i].rev!=0&&t[i].l!=t[i].r))
			return false;
		last=t[i].r;
	}
	printf("1\n%d %d\n",t[l1].l,t[r1].r);
	return true;
}
bool chk(int l1,int r1,int l2,int r2)
{
	for(int i=1;i<=top;i++)t[i]=x[i];
	reverse(l2,r2);
	reverse(l1,r1);
	int last=0;
	for(int i=1;i<=top;i++)
	{
		if(t[i].l!=last+1||(t[i].rev!=0&&t[i].l!=t[i].r))
			return false;
		last=t[i].r;
	}
	printf("2\n%d %d\n",t[l1].l,t[r1].r);
	reverse(l1,r1);
	int ll=0,rr=0;
	for(int i=1;i<l2;i++)ll+=t[i].r-t[i].l+1;rr=ll;
	for(int i=l2;i<=r2;i++)rr+=t[i].r-t[i].l+1;
	printf("%d %d\n",ll+1,rr);
	return true;
}
bool chk(int l1,int r1,int l2,int r2,int l3,int r3)
{
//	cout<<"chk "<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<l3<<' '<<r3<<endl;
	for(int i=1;i<=top;i++)t[i]=x[i];
	reverse(l3,r3);
	reverse(l2,r2);
	reverse(l1,r1);
//	for(int i=1;i<=top;i++)cout<<i<<' '<<t[i].l<<' '<<t[i].r<<' '<<t[i].rev<<endl;
	int last=0;
	for(int i=1;i<=top;i++)
	{
		if(t[i].l!=last+1||(t[i].rev!=0&&t[i].l!=t[i].r))
			return false;
		last=t[i].r;
	}
	printf("3\n%d %d\n",t[l1].l,t[r1].r);
	reverse(l1,r1);
	int ll=0,rr=0;
	for(int i=1;i<l2;i++)ll+=t[i].r-t[i].l+1;rr=ll;
	for(int i=l2;i<=r2;i++)rr+=t[i].r-t[i].l+1;
	printf("%d %d\n",ll+1,rr);
	reverse(l2,r2);
	ll=0,rr=0;
	for(int i=1;i<l3;i++)ll+=t[i].r-t[i].l+1;rr=ll;
	for(int i=l3;i<=r3;i++)rr+=t[i].r-t[i].l+1;
	printf("%d %d\n",ll+1,rr);
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=a[n+1]=-1;
	int last=0;
	for(int i=2;i<=n+1;i++)
	{
		if(abs(a[i]-a[i-1])!=1)
		{
			if(i-2!=last+1)
			{
				top++;
				x[top].l=min(a[last+1],a[i-1]);
				x[top].r=max(a[last+1],a[i-1]);
				x[top].rev=(a[i-1]>a[i-2]?0:1);
				last=i-1;
			}
			else
			{
				top++;
				x[top].l=x[top].r=a[last+1];
				top++;
				x[top].l=x[top].r=a[i-1];
				last=i-1;
			}
		}
	}
//	for(int i=1;i<=top;i++)cout<<i<<' '<<x[i].l<<' '<<x[i].r<<' '<<x[i].rev<<endl;
#define rep(i,j) for(int i=j;i<=top;i++)
	if(chk())return 0;
	rep(l1,1)rep(r1,l1)if(chk(l1,r1))return 0;
	rep(l1,1)rep(r1,l1)rep(l2,1)rep(r2,l2)if(chk(l1,r1,l2,r2))return 0;
	rep(l1,1)rep(r1,l1)rep(l2,1)rep(r2,l2)rep(l3,1)rep(r3,l3)if(chk(l1,r1,l2,r2,l3,r3))return 0;
	cout<<"QAQ\n";//this should not happen
	return 0;
}