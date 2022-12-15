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
int n,m,t[M];
int A[M],B[M],C[M],D[M];
bool ans=true;
multiset<int>L,R;
vector<int>ils[M],irs[M],dls[M],drs[M];
inline bool solve(){
	// for(int i=1;i<=n;i++) debug(A[i])sp,debug(B[i])sp,debug(C[i])sp,debug(D[i])el;
	L.clear(),R.clear();
	for(int i=1;i<=n+n;i++) ils[i].clear(),irs[i].clear(),dls[i].clear(),drs[i].clear();
	for(int i=1;i<=n;i++){
		ils[A[i]].pb(C[i]),irs[A[i]].pb(D[i]);
		dls[B[i]].pb(C[i]),drs[B[i]].pb(D[i]);
	}
	for(int i=1;i<=n+n;i++){
		for(int j=0,TP=ils[i].size();j<TP;++j)
			L.insert(ils[i][j]),R.insert(irs[i][j]);
		if(L.size()>=2){
			set<int>::iterator it=L.end();
			int mxl=(*(--it));
			int mir=(*R.begin());
			if(mir<mxl) return false;
		}
		for(int j=0,TP=dls[i].size();j<TP;++j)
			L.erase(L.find(dls[i][j])),R.erase(R.find(drs[i][j]));
	} return true;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) A[i]=read(),B[i]=read(),C[i]=read(),D[i]=read();

	m=0;
	for(int i=1;i<=n;i++) t[++m]=A[i],t[++m]=B[i]; sort(t+1,t+m+1),m=unique(t+1,t+m+1)-t-1;
	for(int i=1;i<=n;i++) A[i]=lower_bound(t+1,t+m+1,A[i])-t,B[i]=lower_bound(t+1,t+m+1,B[i])-t;

	m=0;
	for(int i=1;i<=n;i++) t[++m]=C[i],t[++m]=D[i]; sort(t+1,t+m+1),m=unique(t+1,t+m+1)-t-1;
	for(int i=1;i<=n;i++) C[i]=lower_bound(t+1,t+m+1,C[i])-t,D[i]=lower_bound(t+1,t+m+1,D[i])-t;

	if(!solve()){puts("NO");return 0;}
	for(int i=1;i<=n;i++) swap(A[i],C[i]),swap(B[i],D[i]);

	puts(solve()?"YES":"NO");

	return 0;
}