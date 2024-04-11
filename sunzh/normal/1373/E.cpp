#include<iostream>
#include<cstdio>
#include<algorithm>
#define llmax 1000000000000000000
#define int unsigned long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,k;
int dig[20];
int s[20];
signed main(){
	T=read();
	s[0]=1;
	for(int i=1;i<=19;++i) s[i]=s[i-1]*10;
	while(T--){
		int minn=llmax;
		n=read(),k=read();
		++k;
		for(int i=0;i<=9;++i){
//			printf("i:%d\n",i);
			int sum=i;
			dig[0]=i;
			if(i+k>10){
//				dig[1]=8;
//				sum=sum+8*k;
				for(int j=1;j<k;++j){
					sum=sum+(i+j)/10+(i+j)%10;
				}
				if(sum>n) continue ;
				if(sum+8*k>=n){
					dig[1]=(n-sum)/k;
					if(dig[1]*k+sum==n){
						minn=min(minn,dig[1]*10+i);
					}
					continue ;
				}
				dig[1]=8;sum+=8*k;
			}
			else{
//				dig[1]=9;
				for(int j=1;j<k;++j) sum+=i+j;
				if(sum>n) continue ;
				if(sum+9*k>=n){
					dig[1]=(n-sum)/k;
					if(dig[1]*k+sum==n){
						minn=min(minn,dig[1]*10+i);
					}
					continue ;
				}
				dig[1]=9;sum+=9*k;
			}
			for(int j=2;j<=19;++j){
				if(sum+9*k>=n){
					dig[j]=(n-sum)/k;
					if(dig[j]*k+sum==n){
						int res=i;
						for(int l=1;l<=j;++l) res+=dig[l]*s[l];
						minn=min(minn,res);
					}
					break ;
				}
				dig[j]=9;sum+=9*k;
			}
		}
		printf("%lld\n",minn>=llmax?-1:minn);
	}
	return 0;
}