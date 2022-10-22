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
int n;
int a[100010];
char str[10];
bool add,fminus,times;
char ans[100010];
const int mxn=131072;
void solve(int l,int r){
	if(l>r) return ;
	int sum=1;
	int cnt=0;
	vector<int>pos;
	pos.pb(l-1);
	for(int i=l;i<=r;++i){
		if(sum<=mxn) sum*=a[i];
		if(a[i]>1){
			++cnt;
			pos.pb(i);
		}
	}
	++cnt;pos.pb(r+1);
	if(sum>mxn){
		for(int i=l;i<r;++i) ans[i]='+';
		for(int i=pos[1];i<pos[cnt-1];++i) ans[i]='*'; 
		return ;
	}
	vector<int>dp(cnt+1),pre(cnt+1);dp[0]=0;
	for(int i=0;i<cnt;++i){
		int s=dp[i]+pos[i+1]-pos[i]-1,t=1;
		for(int j=i+1;j<=cnt;++j){
			t=t*a[pos[j]];
			int r=s+t;
			if(r>dp[j]){
				pre[j]=i;dp[j]=r;
			}
		}
	}
	int ps=cnt;
	while(ps){
		int t=ps;
		ps=pre[ps];
		for(int i=max(l,pos[ps]);i<pos[ps+1];++i) ans[i]='+';
		for(int i=pos[ps+1];i<pos[t];++i) ans[i]='*';
	}
} 
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	scanf("%s",str+1);
	for(int i=1;i<=strlen(str+1);++i){
		switch(str[i]){
			case '+':{add=1; break;}
			case '-':fminus=1;break ;
			case '*':times=1;break ;
		}
	}
	if(!times){
		if(add) for(int i=1;i<n;++i) printf("%d+",a[i]);
		else for(int i=1;i<n;++i) printf("%d-",a[i]);printf("%d\n",a[n]);
		return 0;
	}
	if(!add){
		if(fminus){
			int p=n+1;
			for(int i=1;i<=n;++i) if(a[i]==0){p=i;break ;}
			if(p==n+1){	
				for(int i=1;i<n;++i) printf("%d*",a[i]);printf("%d\n",a[n]);
				return 0;
			}
			for(int i=1;i<p-1;++i) printf("%d*",a[i]);
			if(p!=1) printf("%d-",a[p-1]);
			for(int i=p;i<n;++i) printf("%d*",a[i]);printf("%d\n",a[n]);
		}
		else{
//			if(n==67878) printf("43423423\n");
			for(int i=1;i<n;++i) printf("%d*",a[i]);printf("%d\n",a[n]);
		}
		return 0;
	}
	int l=1,r=l;
	while(l<=n){
		while(a[r]!=0) ++r;
		ans[r-1]='+',ans[r]='+';
		solve(l,r-1);l=r+1;r=l;
	}
	for(int i=1;i<n;++i) printf("%d%c",a[i],ans[i]);printf("%d\n",a[n]);
	return 0;
}