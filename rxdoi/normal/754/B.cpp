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

char s[10][10];

bool check(){
	for (int i=1;i<=4;i++)
		for (int j=1;j<=2;j++){
			if (s[i][j]=='x'&&s[i][j+1]=='x'&&s[i][j+2]=='x') return 1;
		}
	for (int i=1;i<=2;i++)
		for (int j=1;j<=4;j++){
			if (s[i][j]=='x'&&s[i+1][j]=='x'&&s[i+2][j]=='x') return 1;
		}
	for (int i=1;i<=2;i++)
		for (int j=1;j<=2;j++){
			if (s[i][j]=='x'&&s[i+1][j+1]=='x'&&s[i+2][j+2]=='x') return 1;
		}
	for (int i=1;i<=2;i++)
		for (int j=3;j<=4;j++){
			if (s[i][j]=='x'&&s[i+1][j-1]=='x'&&s[i+2][j-2]=='x') return 1;
		}
	return 0;
}

int main(){
	for (int i=1;i<=4;i++) scanf("%s",s[i]+1);
	For(i,1,4+1) For(j,1,4+1)
		if (s[i][j]=='.'){
			s[i][j]='x';
			if (check()){
				puts("YES");
				return 0;
			}
			s[i][j]='.';
		}
	puts("NO");
}