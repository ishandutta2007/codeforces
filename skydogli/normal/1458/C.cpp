#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define mn 1005
#define MN 100005
int T,n,m;
int a[mn][mn],ans[mn][mn];
char ch[MN];
int id[5],tag[5];
int main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)			
				a[i][j]=read();
		}
		for(int i=1;i<=3;++i)id[i]=i,tag[i]=0;
		scanf("%s",ch+1);//
		for(int p=1;p<=m;++p){
			if(ch[p]=='R')tag[id[2]]++;
			if(ch[p]=='L')tag[id[2]]--;
			if(ch[p]=='D')tag[id[1]]++;
			if(ch[p]=='U')tag[id[1]]--;
			if(ch[p]=='I')swap(id[2],id[3]);
			if(ch[p]=='C')swap(id[1],id[3]);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				int A,B,C;
				int _i=(i+tag[1]%n+n-1)%n+1;
				int _j=(j+tag[2]%n+n-1)%n+1;
				int _a=(a[i][j]+tag[3]%n+n-1)%n+1;
				if(id[1]==1)A=_i;
				else A=id[1]==2?_j:_a;
				if(id[2]==1)B=_i;
				else B=id[2]==2?_j:_a;
				if(id[3]==1)C=_i;
				else C=id[3]==2?_j:_a;
				ans[A][B]=C;
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				printf("%d%c",ans[i][j],j==n?'\n':' ');
	}
	return 0;
}