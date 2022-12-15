#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1020
using namespace std;
int read(){
    int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};
char ch[M][M];
bool ran(int x,int y){
	if(x<=1||x>=n||y<=1||y>=m) return false;
	for(int i=0;i<8;i++) if(ch[x+dx[i]][y+dy[i]]=='.') return false;
	return true;
}
bool fd(int x,int y){
	if(ch[x][y]=='.') return true;
	for(int i=0;i<8;i++) if(ran(x+dx[i],y+dy[i])) return true;
	return false;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(); 
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!fd(i,j)){puts("NO");return 0;}
		}
	}
	puts("YES"); return 0;
}