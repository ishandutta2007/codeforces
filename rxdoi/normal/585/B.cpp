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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100+19;

char s[3][N];
int f[N][3];
int n,k;

bool check(int T,int x,int y){
	return y+2*T>n||s[x][y+2*T]=='.';
}
void Main(){
	memset(f,0,sizeof(f));
	n=IN(),k=IN();
	For(i,0,3) scanf("%s",s[i]+1);
	For(i,0,3)
		if (s[i][1]=='s'){
			s[i][1]='.';
			f[0][i]=1;
		}
	For(T,0,n-1) For(i,0,3)
		if (f[T][i]){
			if (!check(T,i,T+2)) continue;
			if (T+2==n){
				puts("YES");
				return;
			}
			For(j,0,3){
				if (abs(i-j)<=1){
					if (check(T,j,T+2)&&check(T+1,j,T+2)) f[T+1][j]=1;
				}
			}
		}
	puts("NO");
}

int main(){
	for (int T=IN();T--;) Main();
}