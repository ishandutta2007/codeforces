#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int query(int x)
{
	if(x<1||x>n)return 1e9;
	cout<<"? "<<x<<endl;
	int z;
	cin>>z;
	return z;
}
int a[233333];
void gao(int l,int r)
{
	if(l==r)
	{
		cout<<"! "<<l<<endl;
		return;
	}
	int mid=(l+r)/2;
	a[mid-1]=query(mid-1);
	a[mid]=query(mid);
	a[mid+1]=query(mid+1);
	if(a[mid]>a[mid-1])gao(l,mid-1);
	else if(a[mid]>a[mid+1])gao(mid+1,r);
	else
	{
		cout<<"! "<<mid<<endl;
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	gao(1,n);
	return 0;
}