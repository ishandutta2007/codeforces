#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int ti,td,tr,te;
char A[4010];
char B[4010];
int f[4010][4010];
int pa[4010][30];
int pb[4010][30];
int n,m;
int main(){
	ti=read(),td=read(),tr=read(),te=read();
	scanf("%s",A+1);scanf("%s",B+1);
	n=strlen(A+1),m=strlen(B+1);
	for(int i=0;i<26;++i){
		int t=-1;
		for(int j=1;j<=n;++j){
			pa[j][i]=t;if(A[j]=='a'+i) t=j;
		}
		t=-1;
		for(int j=1;j<=m;++j){
			pb[j][i]=t;if(B[j]=='a'+i) t=j;
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=m;++i) f[0][i]=ti*i;
	for(int i=1;i<=n;++i) f[i][0]=td*i; 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(A[i]==B[j]){
				f[i][j]=min(f[i-1][j]+td,f[i-1][j-1]);
			}
			else f[i][j]=min(f[i-1][j]+td,f[i-1][j-1]+min(ti+td,tr));
			f[i][j]=min(f[i][j],f[i][j-1]+ti);
			if(i>=2&&j>=2){
				int ta=pa[i][B[j]-'a'];
				int tb=pb[j][A[i]-'a'];
				if(ta!=-1&&tb!=-1){
					f[i][j]=min(f[i][j],f[ta-1][tb-1]+(B[j]==A[i]?0:te)+(j-tb-1)*ti+(i-ta-1)*td);
				}
			}
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}