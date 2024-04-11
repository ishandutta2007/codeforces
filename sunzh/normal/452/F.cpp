#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int lsum[300010],rsum[300010];
int n;
int a[300010];
int tre[300010];
void update(int x,int k){
	while(x<=n){
		tre[x]+=k;
		x+=x&-x;
	}
}
int query(int x){
	int res=0;
	while(x){
		res+=tre[x];
		x-=x&-x;
	}
	return res;
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		if((a[i]<<1)>n){
			lsum[i]=query(n)-query(a[i]-(n-a[i])-1);
		}
		else{
			lsum[i]=query((a[i]<<1)-1);
		}
		update(a[i],a[i]);
	}
	memset(tre,0,sizeof(tre));
	for(int i=n;i>=1;--i){
		if((a[i]<<1)>n){
			rsum[i]=query(n)-query(a[i]-(n-a[i])-1);
		}
		else{
			rsum[i]=query((a[i]<<1)-1);
		}
		update(a[i],a[i]);
	}
	for(int i=1;i<=n;++i){
		if(lsum[i]%(a[i]<<1)!=0&&rsum[i]%(a[i]<<1)!=0){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}