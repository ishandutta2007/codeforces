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
#define vc vector<int>
int T,n,m,k,q;
int a[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		if(n%2050!=0){puts("-1");continue;}
		n/=2050;
		int ans=0;
		while(n){ans+=n%10;n/=10;}
		cout<<ans<<endl;
	}
	return 0;
}