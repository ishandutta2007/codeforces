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

const int N=1000+19;

char s[N][10];
int n,b;

int main(){
	n=IN();
	For(i,1,n+1) scanf("%s",s[i]+1);
	For(i,1,n+1){
		if (s[i][1]=='O'&&s[i][2]=='O') {s[i][1]=s[i][2]='+',b=1;break;}
		if (s[i][4]=='O'&&s[i][5]=='O') {s[i][4]=s[i][5]='+',b=1;break;}
	}
	if (!b){
		puts("NO");
		return 0;
	}
	puts("YES");
	For(i,1,n+1) puts(s[i]+1);
}