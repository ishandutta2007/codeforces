// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<class T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

#define N 1000005

vector<int>inz[N];
int a[N],n;
int mx;

ll f[N];
int cnt[N],ans;

int mu[N];
void xxs(int n){
	static int pr[N],len;
	static bool vis[N];
	len=0;
	mu[1]=1;
	rep(i,2,n){
		if(!vis[i])pr[++len]=i,mu[i]=-1;
		for(int j=1;j<=len&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0)break;
			mu[pr[j]*i]=-mu[i];
		}
	}
}

int main(){
	xxs(1e6);
	n=read();
	rep(i,1,n)a[i]=read(),mx=max(mx,a[i]),cnt[a[i]]=1;
	rep(i,1,mx){
		for(int j=i;j<=mx;j+=i)
			inz[j].pb(i),f[i]+=cnt[j];
//		f[i]=1ll*f[i]*(f[i]-1)/2;
	}
	per(i,mx,1){
		ll g=0;
		for(int j=i;j<=mx;j+=i)
			g+=1ll*mu[j/i]*f[j]*(f[j]-1)/2;
//		printf("g=%d,cnt=%d\n",g,cnt[i]);
		if(g&&!cnt[i]){
			cnt[i]=1;
			for(auto it:inz[i])
				f[it]++;
			ans++;
		}
	}
	print(ans,'\n');
	return 0;
}