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
#define MN 250005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m;
vector<int>a[MN];
int diff(int i,int j){
	int res=0;
	for(int k=1;k<=m;++k)
		res+=(a[i][k]!=a[j][k]);
	return res;
}
int pos;
void chk(int op=0){
	for(int i=1;i<=n;++i)
		if(diff(0,i)>2+op){pos=i;return;}
		else if(diff(0,i)>2){
			vector<int>p;
			for(int j=1;j<=m;++j)
				if(a[0][j]!=a[i][j]){
					int tmp=a[0][j];
					a[0][j]=a[i][j];
					chk();
					a[0][j]=tmp;
				}
			return;
		}
	puts("Yes");
	for(int i=1;i<=m;++i)printf("%lld ",a[0][i]);
	exit(0);
}
int cnt[1<<4];
signed main(){
	n=read();m=read();
	a[0].resize(m+1);
	for(int i=1;i<=n;++i){
		a[i].resize(m+1);
		for(int j=1;j<=m;++j)
			a[i][j]=read();
	}
	a[0]=a[1];
	chk();
	vector<int>p;
	for(int i=1;i<=m;++i)
		if(a[0][i]!=a[pos][i])p.push_back(i);
	if(p.size()>4){puts("No");return 0;}
	int t=pos;
	for(int i=0;i<(1<<p.size());++i){
		cnt[i]=cnt[i>>1]+(i&1);
		if(cnt[i]<=2&&(p.size()-cnt[i])<=2){
			for(int j=0;j<p.size();++j)
				if((i>>j)&1)a[0][p[j]]=a[t][p[j]];
			chk(cnt[i]==1);
			for(int j=0;j<p.size();++j)
				if((i>>j)&1)a[0][p[j]]=a[1][p[j]];
		}
	}
	puts("No");
	return 0;
}