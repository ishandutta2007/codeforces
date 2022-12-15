#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 5020
int n,m,K,A[M],tot,t[M],s[M];
inline bool calc(int w){
	for(int ls=0,rs=K;rs>=0;rs--,ls++){
		int ok=1;
		for(int rt=m-1-K,lt=0;ok>0&&rt>=0;rt--,lt++){
			if(A[ls+lt+1]<w&&A[n-rt-rs]<w) ok=0;
		}
		if(ok) return true;
	} return false;
}
inline int solve(){
	n=read(),m=read(),K=read(),tot=0,K=min(K,m-1);
	for(int i=1;i<=n;i++) A[i]=read(),t[++tot]=A[i];
	sort(t+1,t+tot+1),tot=unique(t+1,t+tot+1)-t-1;
	int res=1,l=2,r=tot;
	for(int i=1;i<=n;i++) A[i]=lower_bound(t+1,t+tot+1,A[i])-t;
	while(l<=r){
		int mid=((l+r)>>1);
		if(calc(mid)) l=mid+1,res=mid;
		else r=mid-1;
	} return t[res];
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%d\n",solve());
	return 0;
}