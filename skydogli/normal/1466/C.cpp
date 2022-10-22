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
int T,n,m;
int a[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		scanf("%s",ch+1);
		n=strlen(ch+1);
		int ans=0;
		for(int i=2;i<=n;++i){
			if(ch[i]==ch[i-1]||ch[i]==ch[i-2]) {
				ans++;
				ch[i]=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}