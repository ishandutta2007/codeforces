#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
char str[51][51];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
		char s='.';bool fl=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) if(str[i][j]!='.'){
				if((i+j)&1){
					if(s=='.') s=str[i][j];
					else if(s!=str[i][j]){ fl=1; }
				}
				else if(s=='.'){
					if(str[i][j]=='R') s='W';else s='R';
				}
				else if(s==str[i][j]) fl=1;
			}
		}
		if(fl) printf("No\n");
		else{
			printf("Yes\n");
			if(s=='.') s='R';
			char t=(s=='R'?'W':'R');
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j) if((i+j)&1) putchar(s);else putchar(t);putchar('\n');
			}
		}
	}
}