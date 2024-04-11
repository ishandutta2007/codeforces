#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int le[Maxn+5],ri[Maxn+5];
int n,m;
map<int,int> ml,mr;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int find_l(int x,int i){
	int now=x+i;
	if(ml.count(now)>0){
		return le[ml[now]];
	}
	return mx(1,x-(m-i)-1);
}
int find_r(int x,int i){
	int now=x-i;
	if(mr.count(now)>0){
		return ri[mr[now]];
	}
	return mn(n,x+(m-i)+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=m;i>0;i--){
		le[i]=find_l(a[i]+1,i);
		ri[i]=find_r(a[i]-1,i);
		ml[a[i]+i]=i;
		mr[a[i]-i]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=find_r(i,0)-find_l(i,0)+1;
	}
	cout<<ans<<endl;
	return 0;
}