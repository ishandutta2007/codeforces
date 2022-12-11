#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
	
using namespace std;

typedef long long  LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 55;
const int mo = 1e9+7;

LL f[N][N][N],g[N][N][N][N];
int n;
int d[N];
int pre[N][3];
LL t[N][N][N];
LL ny[N],js[N];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}

int main(){
	//freopen("data.in","r",stdin);
	n=get();
	fo(i,1,n)d[i]=get();
	fo(i,1,n){
		fo(j,1,2)pre[i][j]=pre[i-1][j];
		pre[i][d[i]-1]++;
	}
	fo(x,0,n)
		fo(y,0,n-x){
			fo(i,0,n)fo(j,0,n)fo(k,0,n)t[i][j][k]=0;
			t[0][0][0]=1;
			fo(i,0,x-1){
				fo(j,0,x)
				if (t[i][j][0]){
					t[i+1][j+1][0]=add(t[i+1][j+1][0],t[i][j][0]);
					if (j)
					t[i+1][j-1][0]=add(t[i+1][j-1][0],t[i][j][0]*j%mo);
				}
			}
			fo(i,x,x+y-1){
				fo(j,0,n)
					fo(k,0,y)
					if (t[i][j][k]){
						t[i+1][j][k+1]=add(t[i+1][j][k+1],t[i][j][k]);
						//1
						t[i+1][j][k]=add(t[i+1][j][k],t[i][j][k]*j%mo);
						if (k)
						t[i+1][j+2][k-1]=add(t[i+1][j+2][k-1],t[i][j][k]*k%mo);
						//2
						if (j>1)
						t[i+1][j-2][k]=add(t[i+1][j-2][k],t[i][j][k]*j*(j-1)/2%mo);
						if (k>1)
						t[i+1][j+2][k-2]=add(t[i+1][j+2][k-2],t[i][j][k]*k*(k-1)/2%mo);
						if (j&&k)
						t[i+1][j][k-1]=add(t[i+1][j][k-1],t[i][j][k]*j*k%mo);
					}
			}
			fo(i,0,n)fo(j,0,n)g[x][y][i][j]=t[x+y][i][j];
		}
	ny[0]=1;
	ny[1]=(mo+1)/2;
	fo(i,2,n)ny[i]=ny[i-1]*ny[1]%mo;
	js[0]=1;
	fo(i,1,n)js[i]=js[i-1]*i%mo;
	if (d[1]==2){
		int x_=pre[3][1]-1,y_=pre[3][2];
		fo(tx,0,n)
			fo(ty,0,n)
			f[3][tx][ty]=g[x_][y_][tx][ty];
	}
	else{
		int x_=pre[4][1],y_=pre[4][2]-1;
		fo(tx,0,n)
			fo(ty,0,n)
			f[4][tx][ty]=g[x_][y_][tx][ty];
	}
	fo(i,1,n)
		fo(x,0,n)
			fo(y,0,n)
			if (f[i][x][y]&&i+x+2*y<=n&&(x||y)){
				int t=i+x+2*y;
				LL tmp=js[x+2*y]*ny[y]%mo;
				int x_=pre[t][1]-pre[i][1],y_=pre[t][2]-pre[i][2];
				fo(tx,0,n)
					fo(ty,0,n)
					if (g[x_][y_][tx][ty])
						f[t][tx][ty]=add(f[t][tx][ty],tmp*f[i][x][y]%mo*g[x_][y_][tx][ty]%mo);
			}
	printf("%I64d\n",f[n][0][0]);
	return 0;
}