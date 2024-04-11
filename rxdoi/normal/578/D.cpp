#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=100000+19;

char s[N];
ll f[2][2][2][2][27],g[2][2][2][2];
ll res,tmp;
int n,m,X,Y,Z,c;

void Upg(int i,int x,int y,int z,int a,int b1,int b2,ll v){
	Y=(a==s[i]-'a'+1?i-2-y+1:i-1-x);
	Z=(b1?i-2-z+1:i-1-x);
	X=(b2?i-1-x+1:max(Y,Z));
	if (X>=i-1){
		Y=max(Y,i-2);
		Z=max(Z,i-2);
		g[c][i-X][i-1-Y][i-1-Z]+=v;
	}
}
void Upf(int i,int x,int y,int z,int a,int b1,int b2,int b,ll v){
	Y=(a==s[i]-'a'+1?i-2-y+1:i-1-x);
	Z=(b1?i-2-z+1:i-1-x);
	X=(b2?i-1-x+1:max(Y,Z));
	if (X>=i-1){
		Y=max(Y,i-2);
		Z=max(Z,i-2);
		f[c][i-X][i-1-Y][i-1-Z][b-'a'+1]+=v;
	}
}

int main(){
	n=IN(),m=IN();
	scanf("%s",s+1);
	f[c][0][0][0][0]=1;
	For(i,1,n+1){
		c^=1;
		memset(f[c],0,sizeof(f[c]));
		memset(g[c],0,sizeof(g[c]));
		For(x,0,2) For(y,0,2) For(z,0,2)
			For(a,0,m+1){
				if (a) f[c^1][x][y][z][a]+=g[c^1][x][y][z];
				if (tmp=f[c^1][x][y][z][a]){
					if (s[i-1]==s[i]){
						Upg(i,x,y,z,a,0,0,tmp);
						Upf(i,x,y,z,a,0,0,s[i],-tmp);
						Upf(i,x,y,z,a,1,1,s[i],tmp);
					} else{
						Upg(i,x,y,z,a,0,0,tmp);
						if (s[i-1]){
							Upf(i,x,y,z,a,0,0,s[i-1],-tmp);
							Upf(i,x,y,z,a,1,0,s[i-1],tmp);
						}
						Upf(i,x,y,z,a,0,0,s[i],-tmp);
						Upf(i,x,y,z,a,0,1,s[i],tmp);
					}
				}
			}
	}
	For(y,0,2) For(z,0,2)
		For(a,1,m+1){
			res+=f[c][1][y][z][a]+g[c][1][y][z];
		}
	printf("%I64d\n",res);
}