#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
int T,n,m;
int a[MN];
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
signed main(){
	T=read();
	while(T--){
		n=read();int k=(read());
		int g=0;
		for(int i=1;i<=n;++i){
			a[i]=(read());
		}
	//	sort(a+1,a+1+n);
		for(int i=1;i<=n;++i){
			if(i>1)g=gcd(g,abs(a[i]-a[i-1]));
		}
		bool ok=0;
		for(int i=1;i<=n;++i)
			if(abs(k-a[i])%g==0){puts("YES");ok=1;break;}
		if(!ok) puts("NO");
	}	
	return 0;
}