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
char a[MN];
signed main(){
	T=read();
	while(T--){
		scanf("%s",a+1);
		int n=strlen(a+1);
		int GG=0;
		int s=0;
		for(int i=1;i<=n;++i){
			if(a[i]=='B')s--;
			else s++;
			if(s<0)GG=1;
		}
		puts((GG||a[n]!='B'||a[1]=='B')?"NO":"YES");
			
	}
	return 0;
}