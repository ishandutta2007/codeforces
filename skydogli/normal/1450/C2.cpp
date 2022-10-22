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
#define MN 305
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n;
char ch[MN][MN],ans[MN][MN];
bool chk(int A,int B){
	int res=0,k=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(ch[i][j]!='.'){
				k++;
				char v=ch[i][j];
				if((i+j)%3==A)v='X';
				if((i+j)%3==B)v='O';
				ans[i][j]=v;
				res+=(v!=ch[i][j]);	
			}
			else ans[i][j]='.';
		}
//	cerr<<A<<" "<<B<<": "<<res<<endl;
	return res<=k/3;
}
void out(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			putchar(ans[i][j]);
		puts("");
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)scanf("%s",ch[i]+1);
		bool ok=0;
		for(int i=0;i<3&&!ok;++i)
			for(int j=0;j<3;++j)
				if(i!=j&&chk(i,j)){
					ok=1;out();break;
				}
		assert(ok);
	}
	return 0;
}