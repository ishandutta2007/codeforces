#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
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

int n,p;
int col[N];
LL f[N][N][N][N];
LL mi[N];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}

int main(){
	n=get();p=get();
	fo(i,1,n)col[i]=get();
	f[0][0][0][0]=1;
	mi[0]=1;
	fo(i,1,n)mi[i]=mi[i-1]*2%mo;
	fo(i,1,n){
		//0
		if(col[i]==0||col[i]==-1){
			fo(c00,0,i-1)
				fo(c01,0,i-1)
					fo(c10,0,i-1)
					if(f[i-1][c00][c01][c10]){
						int c11=i-1-c00-c01-c10;
						//c00
						if (c11){
							f[i][c00+1][c01][c10]=add(f[i][c00+1][c01][c10],f[i-1][c00][c01][c10]*mi[c00+c01+c10+c11-1]%mo);
						}
						//c01
						f[i][c00][c01+1][c10]=add(f[i][c00][c01+1][c10],f[i-1][c00][c01][c10]*mi[c00+c01+c10]%mo*(c11?mi[c11-1]:1)%mo);
					}
		}
		if(col[i]==1||col[i]==-1){
			fo(c00,0,i-1)
				fo(c01,0,i-1)
					fo(c10,0,i-1)
					if(f[i-1][c00][c01][c10]){
						int c11=i-1-c00-c01-c10;
						//c10
						if (c01){
							f[i][c00][c01][c10+1]=add(f[i][c00][c01][c10+1],f[i-1][c00][c01][c10]*mi[c10+c11+c00+c01-1]%mo);
						}
						//c11
						f[i][c00][c01][c10]=add(f[i][c00][c01][c10],f[i-1][c00][c01][c10]*mi[c10+c11+c00]%mo*(c01?mi[c01-1]:1)%mo);
					}
		}
	}
	LL ans=0;
	fo(c00,0,n)
		fo(c01,0,n)
			fo(c10,0,n)
			if(f[n][c00][c01][c10]){
				int c11=n-c00-c01-c10;
				if (((c01+c11)&1)==p)ans=add(ans,f[n][c00][c01][c10]);
			}
	cout<<ans<<endl;
	return 0;
}