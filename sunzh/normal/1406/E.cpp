#include<bits/stdc++.h>
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
int n;
bool vis[100000+10];
int p[100000+10];
int tot;
int num;
void get_prime(){
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) p[++tot]=i;
		for(int j=1;p[j]*i<=n;j++){
			vis[p[j]*i]=1;
			if(i%p[j]==0) break ;
		}
	}
}
//set<int>st;
int ans=1;
int times=0;
void findans(int x){
	int sum=1;
	for(int i=x;i<x+100&&i<=tot;++i){
		printf("A %d\n",p[i]);fflush(stdout);
		int x=read();
//		for(int j=1;j*p[i]<=n;++j) if(st.count(j*p[i])) ++cnt;
		if(x){
			sum=1ll*sum*p[i];
			long long tmp=1ll*p[i]*p[i];
			for(tmp;tmp<=n;tmp=1ll*tmp*p[i]){
				if(tmp<=n)printf("A %d\n",tmp);else break ;fflush(stdout);
				int a=read();
				if(a) sum=sum*p[i];
				else break ;
			}
		}
	}
	ans=sum*ans;
}
int main(){
	n=read();
	num=n;
	get_prime();
	for(int i=1;i<=tot;i+=100){
		for(int j=1;j<=100&&i+j-1<=tot;++j){
			printf("B %d\n",p[i+j-1]);
			fflush(stdout);
			int x=read();
			num-=x;
//			for(int k=1;k*p[i+j-1]<=n;++k) st.erase(k*p[i+j-1]);
		}
//		printf("siz:%d\n",st.size());fflush(stdout);
		printf("A 1\n");
		fflush(stdout);
		int x=read();
		if(x>num){
			num=x;
			findans(i);
		}
	}
	printf("C %d\n",ans);
	return 0;
}