#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=400000+19;
const int oo=(1<<30)-1;

char A[N],B[N],s[N];
int F[20][N];
int SA[N],rk[N],h[N],Lg[N],id[N],ans[N],val[N];
int n,m,q;

void Build_SA(int n){
	static int tmp[N],cnt[N],trk[N],p;
	For(i,1,n+1) cnt[s[i]]++,p=max(p,int(s[i]));
	For(i,1,p+1) cnt[i]+=cnt[i-1];
	for (int i=n;i;i--) SA[cnt[s[i]]--]=i;
	rk[SA[1]]=p=1;
	For(i,2,n+1) rk[SA[i]]=(s[SA[i]]==s[SA[i-1]]?p:++p);
	for (int k=1;k<=n;k<<=1){
		memset(cnt,0,sizeof(cnt));
		For(i,1,n+1) cnt[rk[i+k]]++;
		For(i,1,p+1) cnt[i]+=cnt[i-1];
		for (int i=n;i;i--) tmp[cnt[rk[i+k]]--]=i;
		memset(cnt,0,sizeof(cnt));
		For(i,1,n+1) cnt[rk[i]]++;
		For(i,1,p+1) cnt[i]+=cnt[i-1];
		for (int i=n;i;i--) SA[cnt[rk[tmp[i]]]--]=tmp[i];
		trk[SA[1]]=p=1;
		For(i,2,n+1){
			trk[SA[i]]=(rk[SA[i]]==rk[SA[i-1]]&&rk[SA[i]+k]==rk[SA[i-1]+k]?p:++p);
		}
		memcpy(rk,trk,sizeof(trk));
	}
	for (int i=1,j=0;i<=n;i++){
		if (rk[i]==1) continue;
		while (s[i+j]==s[SA[rk[i]-1]+j]) j++;
		h[rk[i]]=j;
		if (j) j--;
	}
	For(i,1,n+1) F[0][i]=h[i];
	For(x,1,20){
		for (int i=1;i+(1<<x)-1<=n;i++){
			F[x][i]=min(F[x-1][i],F[x-1][i+(1<<x-1)]);
		}
	}
}
int LCP(int x,int y){
	if (x==y) return oo;
	x=rk[x],y=rk[y];
	if (x>y) swap(x,y);
	x++;
	int t=Lg[y-x+1];
	return min(F[t][x],F[t][y-(1<<t)+1]);
}
bool cmp(int x,int y){
	static int xl[3],xr[3],yl[3],yr[3];
	xl[0]=1;	xr[0]=x;
	xl[1]=n+2;	xr[1]=n+m+1;
	xl[2]=x+1;	xr[2]=n;
	yl[0]=1;	yr[0]=y;
	yl[1]=n+2;	yr[1]=n+m+1;
	yl[2]=y+1;	yr[2]=n;
	for (int i=0,j=0;;){
		for (;i<3&&xl[i]>xr[i];i++);
		for (;j<3&&yl[j]>yr[j];j++);
		if (i==3) return x<y;
		int len=LCP(xl[i],yl[j]);
		int mn=min(xr[i]-xl[i]+1,yr[j]-yl[j]+1);
		if (len>=mn){
			xl[i]+=mn;
			yl[j]+=mn;
		} else{
			return s[xl[i]+len]<s[yl[j]+len];
		}
	}
}

struct QType{
	int l,r,x,y,id;
};vector<QType> V[N];
int l,r,x,y,k,S;
Vi T[N];

int cal(int x,int y){
	if (x==-1) return y;
	if (y==-1) return x;
	return val[x]<val[y]?x:y;
}
void Work1(int k){
	For(i,0,n+1) T[i%k].pb(i);
	For(b,0,k){
		For(i,0,T[b].size()) F[0][i]=T[b][i];
		For(x,1,20){
			for (int i=0;i+(1<<x)-1<T[b].size();i++){
				F[x][i]=cal(F[x-1][i],F[x-1][i+(1<<x-1)]);
			}
		}
		for (QType Q:V[k])
			if (Q.x<=b&&b<=Q.y){
				int l=Q.l/k,r=Q.r/k;
				if (Q.l%k>b) l++;
				if (Q.r%k<b) r--;
				if (l<=r){
					int t=Lg[r-l+1];
					ans[Q.id]=cal(ans[Q.id],F[t][l]);
					ans[Q.id]=cal(ans[Q.id],F[t][r-(1<<t)+1]);
				}
			}
	}
	For(i,0,k) T[i].clear();
}
void Work2(int k){
	for (QType Q:V[k]){
		for (int x=Q.x,y=Q.y;x<=n;x+=k,y+=k){
			int l=max(x,Q.l),r=min(y,Q.r);
			if (l<=r){
				int t=Lg[r-l+1];
				ans[Q.id]=cal(ans[Q.id],F[t][l]);
				ans[Q.id]=cal(ans[Q.id],F[t][r-(1<<t)+1]);
			}
		}
	}
}

int main(){
	memset(ans,-1,sizeof(ans));
	For(i,2,N) Lg[i]=Lg[i>>1]+1;
	
	scanf("%s%s%d",A+1,B+1,&q);
	n=strlen(A+1);
	m=strlen(B+1);
	For(i,1,n+1) s[i]=A[i];
	s[n+1]='#';
	For(i,1,m+1) s[i+n+1]=B[i];
	Build_SA(n+m+1);
	For(i,0,n+1) id[i]=i;
	sort(id,id+n+1,cmp);
	For(i,0,n+1) val[id[i]]=i;
	
	For(i,1,q+1){
		l=IN(),r=IN(),k=IN(),x=IN(),y=IN();
		V[k].pb((QType){l,r,x,y,i});
	}
	S=70;
	For(i,1,S+1) Work1(i);
	For(i,0,n+1) F[0][i]=i;
	For(x,1,20){
		for (int i=0;i+(1<<x)-1<=n;i++){
			F[x][i]=cal(F[x-1][i],F[x-1][i+(1<<x-1)]);
		}
	}
	For(i,S+1,n+1) Work2(i);
	
	For(i,1,q+1) printf("%d ",ans[i]);
	puts("");
}