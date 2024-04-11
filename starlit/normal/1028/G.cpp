#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10001,K=6;
const ll M=10004205361450474ll;
ll f[N][K],now=1,qry[N];
int t,x;
ll cal(ll x,int d){
	if(!d)return 0;
	if(x>=N)return cal(N-1,d);
	if(f[x][d])return f[x][d];
	ll re=x;
	for(int i=0;i<=x;i++)
	re+=cal(re,d-1)+1;
	return f[x][d]=re-x-1;
}
int main(){
	for(int i=5;i;i--){
		t=now<N?now:(N-1),qry[0]=now-1,now+=cal(now,i-1);
		for(int j=0;j<t;j++){
			qry[j+1]=now;
			now+=cal(now+1,i-1)+1;
		}
		printf("%d",t);
		for(int j=1;j<=t;j++)printf(" %lld",qry[j]);
		puts("");fflush(stdout);
		scanf("%d",&x);
		if(x<0)return 0;
		now=qry[x]+1;
	}
}