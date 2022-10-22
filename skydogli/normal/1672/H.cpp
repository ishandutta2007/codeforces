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
int T,n,q;
int a[MN],b[MN];
char ch[MN];
signed main(){
	n=read();q=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i){
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(ch[i]==ch[i-1]){
			if(ch[i]=='0')a[i]++;
			else b[i]++;
		}
	}
	while(q--){
		int l=read(),r=read();
		printf("%lld\n",max(a[r]-a[l],b[r]-b[l])+1);
	}
	return 0;
}