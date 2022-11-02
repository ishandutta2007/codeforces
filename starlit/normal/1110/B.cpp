#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,m,k,l,x,y,a[N],t;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(i==1)l=1-x;
		else a[t++]=x-y-1;
		y=x;
	}l+=y;
	sort(a,a+t);
	for(int i=t-1;i>=max(0,t-k+1);i--)
	l-=a[i];
	printf("%d",l);
}