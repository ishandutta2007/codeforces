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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int N=100010;
int n,x,y,k,p,a[N],tot[N],num[N]; 
char str[N];
signed main(){
	int T=read();
	while(T--){
		n=read(),p=read(),k=read();
		int ans=(1ll<<60);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++)a[i]=str[i]-'0',tot[i]=num[i]=0;
		y=read();x=read();
		for(int i=1;i<=n;i++)tot[i%k]+=a[i],num[i%k]++;
		for(int i=1;i<p;i++)tot[i%k]-=a[i],num[i%k]--;
		for(int i=1;i<=n-p+1;i++)
		{
			int sum=(i-1)*x;
			int s=i+p-1;
			sum+=(num[s%k]-tot[s%k])*y;
			tot[s%k]-=a[s];num[s%k]--;
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}