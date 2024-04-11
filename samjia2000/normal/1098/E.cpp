#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;

int n,a[N];
int now[N],R[N];
LL cnt[N];
bool bz[N];
LL pre[N],pc[N];

LL solve(LL n,LL A,LL B,LL C){
	//\sum_{i=0}^n (A*i+B)/C
	if (!n)return B/C;
	if ((A*n+B)/C==(B/C))return (B/C)*(n+1);
	if (A>=C||B>=C)return solve(n,A%C,B%C,C)+(A/C)*(n*(n+1)/2)+(B/C)*(n+1);
	return solve((A*n+B)/C-1,C,(A*n+B)%C,A)+(A*n+B)/C;
}

LL solve(LL L){
	LL ret=0;
	LL w1=1;
	for(;w1<=1e5&&pre[w1]<=L;w1++);
	if (w1>1e5)return 1ll*n*(n+1)/2*(1ll*n*(n+1)/2+1)/2;
	LL w0=1,c1=(L-pre[w1-1])/w1;
	ret=(pc[w1-1]+c1)*(pc[w1-1]+c1+1)/2;
	for(;w1<1e5||c1<cnt[w1];){
		LL vr=pre[w1-1]+(c1+1)*w1;
		while(vr-pre[w0]>L)w0++;
		if (w0==w1){
			ret=ret+(cnt[w1]-c1)*(L/w1);
			c1=cnt[w1];
		}
		else{
			LL S=vr-pre[w0-1];
			LL A=w1,B=w0;
			LL lj=(S-L-1)/B+1,rj=cnt[w0];
			LL ri=cnt[w1]-1-c1,li=0;
			LL rj1=(ri*A+S-L-1)/B+1;
			if (rj1<=rj)rj=rj1;
			else ri=(rj*B+L-S)/A;
			LL T=pc[w1-1]-pc[w0-1]+c1+1;
			ret=ret+(T-1)*(ri+1)+ri*(ri+1)/2-solve(ri,A,S-L-1,B);
			c1+=ri+1;
		}
		
		while(w1<1e5&&c1==cnt[w1])w1++,c1=0;
	}
	return ret;
}

int main(){
	n=get();
	fo(i,1,n){
		int x=get();
		int u=sqrt(x);
		fo(d,1,u)
		if (x%d==0){
			int r=d;
			if (R[r]!=i-1)now[r]=0;
			cnt[r]+=(++now[r]);
			R[r]=i;
			if (d!=x/d){
				int r=x/d;
				if (R[r]!=i-1)now[r]=0;
				cnt[r]+=(++now[r]);
				R[r]=i;
			}
		}
	}
	fo(p,2,1e5)
	if (!bz[p])
		fo(i,1,1e5/p)cnt[i]-=cnt[i*p],bz[i*p]=1;
	fo(i,1,1e5)pre[i]=pre[i-1]+cnt[i]*i,pc[i]=pc[i-1]+cnt[i];
	LL l=0,r=1e15,ans;
	LL M=1ll*n*(n+1)/2;
	M=M*(M+1)/2;
	M=(M+1)/2;
	while(l<=r){
		LL mid=(l+r)/2;
		if (solve(mid)>=M)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}