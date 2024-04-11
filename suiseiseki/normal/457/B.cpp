#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5],b[Maxn+5];
int n,m;
ll mn(int a,ll b){
	return a<b?a:b;
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	ll sum_1=0,sum_2=0;
	ll ans_1,ans_2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum_1+=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		sum_2+=b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	ans_1=sum_2;
	ans_2=sum_1;
	for(int i=1;i<n;i++){
		ans_1+=mn(a[i],sum_2);
	}
	for(int i=1;i<m;i++){
		ans_2+=mn(b[i],sum_1);
	}
	cout<<mn(ans_1,ans_2)<<endl;
	return 0;
}