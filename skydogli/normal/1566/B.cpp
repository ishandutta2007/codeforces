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
int T,n,m;
int a[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		scanf("%s",ch+1);n=strlen(ch+1);
		int r=0;
		for(int i=1;i<=n;++i){
			if(ch[i]=='0'&&ch[i-1]!='0')r++;
		}
		printf("%lld\n",min(r,2ll));
	}
	return 0;
}