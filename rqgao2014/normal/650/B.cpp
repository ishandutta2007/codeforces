#include<bits/stdc++.h>
using namespace std;

int n,a,b,T,c[1000005],ans;
char s[1000005];

inline bool check(int t,int i){
//	printf("%d %d\n",t,i);
	int g=(c[n]-c[i-1])*b+(n-i)*a+n-i+1;
	if(T-t>=g) return 1;
	return 0;
}
inline void solve(){
	for(int i=1;i<=n;i++) c[i]=c[i-1]+(s[i]=='w');
	int pt=n+1;
	for(int i=n;i;i--){
		int t=(i-1)*a+c[i]*b+i;
		if(t>T) continue;
		ans=max(ans,i);
//		printf("%d\n",i);
		if(t+i*a>T) continue;
		while(pt>i+1&&check(t+i*a,pt-1)) pt--;
//		printf("pt:%d\n",pt);
		ans=max(ans,i+n-pt+1);
	}
}

int main(){
	scanf("%d%d%d%d",&n,&a,&b,&T);
	scanf("%s",s+1);
	solve();
	reverse(s+2,s+n+1);solve();
	printf("%d\n",ans);
	return 0;
}
/*
3 1 100 10
whw
*/