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

#define M 400200
LL n,X[M],Y[M],x[M],y[M],d[M];
LL ans;
int id[M];
inline bool cmp(int a,int b){
	if(d[a]!=d[b]) return d[a]<d[b];
	return X[a]*Y[b]>X[b]*Y[a];
}
inline LL cross(int a,int b){return x[a]*y[b]-x[b]*y[a];}
inline LL C3(LL K){if(K<3) return 0ll;return K*(K-1)*(K-2)/6;}
inline void solve(int I){
	int m=0;
	for(int i=1;i<=n;i++) if(i!=I){
		id[++m]=i,X[i]-=X[I],Y[i]-=Y[I]; 
		if(X[i]>0&&Y[i]>=0) d[i]=1;
		if(X[i]<=0&&Y[i]>0) d[i]=2;
		if(X[i]<0&&Y[i]<=0) d[i]=3;
		if(X[i]>=0&&Y[i]<0) d[i]=4;
		// debug(i)sp,debug(X[i])sp,debug(Y[i])sp,debug(d[i])el;
	} sort(id+1,id+m+1,cmp),X[I]=Y[I]=0;
	for(int i=1;i<=m;i++) x[i]=X[id[i]],y[i]=Y[id[i]];
	for(int i=1;i<=m;i++) x[i+m]=x[i],y[i+m]=y[i];
	// for(int i=1;i<=m;i++) debug(x[i])sp,debug(y[i])el;
	int rs=1;
	for(int i=1;i<=m;i++){
		rs=max(rs,i);
		while(rs+1<(i+m)&&cross(i,rs+1)>0) ++rs;
		ans-=C3(rs-i);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) X[i]=read(),Y[i]=read();
	ans=n*((n-1)*(n-2)*(n-3)*(n-4)/24);
	// solve(4);
	// debug(ans)el;
	// return 0;
	for(int i=1;i<=n;i++) solve(i);
	printf("%lld\n",ans);
	return 0;
}