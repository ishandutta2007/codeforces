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
int T;
int n;
int solve(int x){
	int p=(x-1)/3+1,q=x%3;
	if(p==1){
		if(q==1) return 1;if(q==2) return 2;return 3;
	}
	int a,b,c;
	for(int s=1,t=0;t<=p;s*=4){
		t+=s;
		if(t>=p){
			t-=s;
			a=(p-t)+s-1;
			break ;
		}
	}
	b=0;
	if(q==1) return a;
	int tmp=p;
	for(int t=1;1;t<<=2){
//		printf("p:%d,t:%d\n",p,t);
		if(t>=p){
			b=(t<<1);
			for(int k=4;k<=t;k<<=2){
				int l=p%k;
				if(l==0) l=k;
				int cnt=(l-1)/(k>>2);if(cnt==1) b+=(k>>1);
				if(cnt==2) b+=(k>>2)*3;
				if(cnt==3) b+=(k>>2);
//				if(!cnt) break ;
			}
			break ;
		}
		p-=t;
	}
	if(q==2) return b;
	return a^b;
}
signed main(){
	T=read();
	while(T--){
		n=read();
		print(solve(n));putchar('\n');
	}
}