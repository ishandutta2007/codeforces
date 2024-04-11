#include<cstdio>
#include<iostream>
using namespace std;
const int o=510;
int T,n,a[o],b[o],cnt,L[o],R[o];
inline void opt(int l,int r){for(L[++cnt]=l,R[cnt]=r;l<r;swap(a[l++],a[r--]));}
inline bool chk(int p){
	for(int i=p;i<=n;++i) if(a[i-1]==b[p]&&a[i]==b[p-1]){opt(p-1,i);return true;}
	for(int i=n;i>p;--i) if(a[i-1]==b[p-1]&&a[i]==b[p]){
		for(int j=i-1;j>=p;--j) for(int k=i;k<=n;++k) if(a[j]==a[k]){opt(j,k);return true;}
		break;
	}
	return false;
}
inline bool wrk(){
	if(cnt>n*n) return false;
	for(int i=2;i<n;++i) if(a[i]^b[i]) if(chk(i)) return true;else{cnt=o*o;return false;}
	return false;
}
inline void slv(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	if(a[1]-b[1]||a[n]-b[n]){printf("NO\n");return;}
	for(;wrk(););
	if(cnt>n*n){printf("NO\n");return;}
	printf("YES\n%d\n",cnt);
	for(int i=1;i<=cnt;++i) printf("%d %d\n",L[i],R[i]);
}
int main(){
	for(scanf("%d\n",&T);T--;cnt=0) slv();
	return 0;
}