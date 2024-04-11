#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
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
int n;
int a[100010];
int cnt1,cnt2;
int a1[100010],a2[100010];
bool flag;
signed main(){
	T=read();
	while(T--){
		flag=0;
		cnt1=cnt2=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i){
			if(a[i]==0) flag=1;
			if(a[i]>0) a1[++cnt1]=a[i];
			if(a[i]<0) a2[++cnt2]=a[i];
		}
		sort(a1+1,a1+cnt1+1);sort(a2+1,a2+cnt2+1);
		if(cnt1+cnt2<5) printf("0\n");
		else{
			int ans=-0x3f3f3f3f3f3f3f3f;
			if(flag) ans=0;
			for(int i=0;i<=5&&i<=cnt2;i+=2){
				if(i+cnt1<5) continue ;
				int sum=1;
				for(int j=1;j<=i;++j) sum=sum*a2[j];
				for(int j=1;j+i<=5;++j) sum=sum*a1[cnt1-j+1];
				ans=max(ans,sum);
			}
			for(int i=1;i<=5&&i<=cnt2;i+=2){
				if(i+cnt1<5) continue ;
				int sum=1;
				for(int j=1;j<=i;++j) sum=sum*a2[cnt2-j+1];
				for(int j=1;j+i<=5;++j) sum=sum*a1[j];
				ans=max(ans,sum);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}