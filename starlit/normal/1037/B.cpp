#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
using namespace std;
int n,s,a[N];
long long ans;
int main(){
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)
	scanf("%d",a+i);
	sort(a,a+n);
	if(a[n>>1]>s){
		for(int i=n>>1;i>=0&&a[i]>s;i--)
		ans+=a[i]-s;
	}
	else for(int i=n>>1;i<n&&a[i]<s;i++)
	ans+=s-a[i];
	printf("%I64d",ans);
}