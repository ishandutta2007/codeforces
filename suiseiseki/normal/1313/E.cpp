#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=500000;
typedef long long ll;
int n,m;
char a[Maxn+5],b[Maxn+5],s[Maxn<<1|5];
char s_a[Maxn*3+5],s_b[Maxn*3+5];
int now[Maxn*3+5];
int num_a[Maxn+5],num_b[Maxn+5];
ll f[2][Maxn<<1|5];
void z_fun(char *s,int *a,int n){
	int l=1,r=1;
	for(int i=2;i<=n;i++){
		a[i]=0;
		if(i<=r){
			a[i]=min(r-i,a[i-l+1]);
		}
		while(s[a[i]+1]==s[i+a[i]]){
			a[i]++;
		}
		if(i+a[i]>r){
			l=i;
			r=i+a[i];
		}
	}
}
void add(ll *f,int x,int val){
	for(int i=x;i>0;i-=(i&(-i))){
		f[i]+=val;
	}
}
ll sum(ll *f,int x){
	ll ans=0;
	if(x==0){
		x++;
	}
	for(int i=x;i<=m;i+=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		s_a[i]=s[i];
	}
	for(int i=1;i<=n;i++){
		s_a[i+m]=a[i];
	}
	for(int i=1;i<=n;i++){
		s_b[i]=b[i];
	}
	for(int i=1;i<=m;i++){
		s_b[i+n]=s[i];
	}
	reverse(s_b+1,s_b+1+n+m);
	z_fun(s_a,now,n+m);
	for(int i=1;i<=n;i++){
		num_a[i]=min(m-1,now[i+m]);
	}
	z_fun(s_b,now,n+m);
	for(int i=1;i<=n;i++){
		num_b[i]=min(m-1,now[n+m-i+1]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(num_a[i]>0){
			add(f[0],num_a[i],1);
			add(f[1],num_a[i],num_a[i]);
		}
		if(i>=m&&num_a[i-m+1]>0){
			add(f[0],num_a[i-m+1],-1);
			add(f[1],num_a[i-m+1],-num_a[i-m+1]);
		}
		if(num_b[i]){
			ans+=sum(f[1],m-num_b[i])+(num_b[i]-m+1)*sum(f[0],m-num_b[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}