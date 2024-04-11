#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n;
int sum;
long long ans;
char a[100010];
long long cnt[2000010];
int main(){
	T=read();
	while(T--){
		sum=1000000;ans=0;
		n=read();
		memset(cnt,0,sizeof(cnt));
		cnt[sum]=1;
		scanf("%s",a+1);
		for(int i=1;i<=n;++i){
			sum=sum+a[i]-'1';
			ans=ans+cnt[sum];
			++cnt[sum];
		}
		printf("%lld\n",ans);
	}
	return 0;
}