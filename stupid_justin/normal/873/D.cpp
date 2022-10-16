#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,k;
int a[maxn];
int tmp[maxn];
bool dfs(int l,int r,int x)
{
	if(r-l<=1) return x==1;
	x--;
	if(x==0) return 1;
	int mid=(l+r+1)/2;
	if(x%2==1) return 0;
	int t1,t2;
	if((x/2)%2==0)
	{
		t1=x/2+1;
		t2=x/2-1;
	}
	else t1=t2=x/2;
	bool s=dfs(l,mid,t1)&&dfs(mid,r,t2);
	if(!s) return s;
	int p = l;
	for(int i=mid;i<r;i++) tmp[p++]=a[i];
	for(int i=l;i<mid;i++) tmp[p++]=a[i];
	for(int i=l;i<r;i++) a[i]=tmp[i];
	return s;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++) a[i]=i+1;
	bool s=dfs(0,n,k);
	if(!s) cout<<-1<<endl;
	else
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
}