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

int n;
char s[N][N];
int t[N*2][N*2];
bool bz[N][N];

int main(){
	n=get();
	fo(i,1,n){
		char ch;
		while(ch=getchar(),ch!='x'&&ch!='.'&&ch!='o');
		fo(j,1,n){
			s[i][j]=ch;
			ch=getchar();
		}
	}
	int q=0;
	fo(i,1,n)
		fo(j,1,n)
		if (s[i][j]=='o'){
			fo(x,-n+1,n-1)
				fo(y,-n+1,n-1){
					if (i+x<1||i+x>n||j+y<1||j+y>n){t[x+N][y+N]++;continue;}
					if (s[i+x][j+y]=='o'||s[i+x][j+y]=='x')t[x+N][y+N]++;
				}
			q++;
		}
	fo(i,1,n)
		fo(j,1,n)
		if (s[i][j]=='o')
			fo(x,-n+1,n-1)
				fo(y,-n+1,n-1)
				if (t[x+N][y+N]==q){
					if (i+x<1||i+x>n||j+y<1||j+y>n)continue;
					bz[i+x][j+y]=1;
				}
	bool ans=0;
	fo(i,1,n)
		fo(j,1,n)
		if ((s[i][j]=='x'&&!bz[i][j])||(s[i][j]=='.'&&bz[i][j]))ans=1;
	if (ans)printf("NO\n");
	else{
		printf("YES\n");
		fo(x,-n+1,n-1){
			fo(y,-n+1,n-1){
				if (x==0&&y==0){putchar('o');continue;}
				if (t[x+N][y+N]==q){putchar('x');continue;}
				putchar('.');
			}
			putchar('\n');
		}
	}
	return 0;
}