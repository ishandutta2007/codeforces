#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000;
int n,a[N],b[N],len,_a[N];ll qz[N],f[N];
void qq(int *a, int n){
	/*ll res=0;
	rep(i,1,x)res+=min(a[i],n-x);
	int tot=0;rep(i,1,x)tot^=(a[i]&1);if((tot&1)!=(res&1))res--;
	return res;*/
	rep(i,0,n)f[i]=0;
	for(int i=n,j=0;i>=1;i--){
		while(j+1<=i&&a[j+1]<=n-i)j++;j=min(j,i);
		f[i]=qz[j]+1LL*(n-i)*(i-j);
	}
	
	int tot=0;a[0]=0;
	rep(i,0,n){
		tot^=a[i]&1;if((tot&1)!=(f[i]&1))f[i]--;
	}
}
int ck(int c){
	rep(i,1,n+1)_a[i]=a[i];
	c=b[c];int p=0;while(p+1<=n&&_a[p+1]<c)p++;
	per(i,n,p+1)_a[i+1]=_a[i];_a[p+1]=c;//ins p+1 --> n+1
	rep(i,1,n+1)qz[i]=qz[i-1]+_a[i];qq(_a,n+1);
	rep(x,0,n)if(qz[n+1]-qz[x]-f[x]>1LL*(n+1-x)*(n+1-x-1)){
		if(x<=p)return 1;//da
		return -1;//xiao
	}
	// 
	
	return 0;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);sort(a+1,a+n+1);
	int t=0;rep(i,1,n)t^=a[i];t=t&1;
	for(int i=t;i<=n;i+=2)b[++len]=i;
	int l=1,r=len;
	while(l<=r){
		int mid=(l+r)>>1,t=ck(mid);
		if(t==0){
			int L=1,R=mid-1,l=mid,r=mid;
			while(L<=R){
				int mid=(L+R)>>1;
				if(ck(mid)==0)l=mid,R=mid-1;else L=mid+1;
			}
			L=mid+1,R=len;
			while(L<=R){
				int mid=(L+R)>>1;
				if(ck(mid)==0)r=mid,L=mid+1;else R=mid-1;
			}
			rep(i,l,r)printf("%d ",b[i]);
			return 0;
		}
		if(t==1)r=mid-1;else l=mid+1;
	}
	puts("-1");
	return 0;
}