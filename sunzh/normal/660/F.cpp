#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const double eps=1e-12;
int n;
int a[200010]; 
int sum1[200010],sum2[200010];
int stk[200010];
int top;
double getx(int id){
	if(id==0) return 0;
	return id-1;
}
double gety(int id){
	if(id==0) return 0;
	return (id-1)*(sum1[id-1])-sum2[id-1];
}
double getslope(int x,int y){
	return (gety(y)-gety(x))/(getx(y)-getx(x)+eps);
}
int calc(int l,int r){
	return sum2[r]-sum2[l-1]-(l-1)*(sum1[r]-sum1[l-1]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) sum1[i]=sum1[i-1]+a[i],sum2[i]=sum2[i-1]+a[i]*i;
	int ans=0;
	for(int i=1;i<=n;++i){
		if(top>1){
			while(top>1&&getslope(stk[top-1],stk[top])<getslope(stk[top-1],i)) --top;
			stk[++top]=i;
		}
		else{
			stk[++top]=i;
		}
		int l=2,r=top;
		double k=sum1[i];
		int res=1;
		while(l<=r){
			int mid=l+r>>1;
			if(getslope(stk[mid-1],stk[mid])>=k)res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,calc(stk[res],i));
	}
	print(ans);
}