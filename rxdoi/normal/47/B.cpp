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

string s[3];
int vis[3];
int mn=-1,se;

int main(){
	For(i,0,3) cin>>s[i];
	For(i,0,3){
		if (s[i][1]=='>') swap(s[i][0],s[i][2]),s[i][1]='<';
		vis[s[i][0]-'A']++;
	}
	For(i,0,3){
		if (vis[i]==2) mn=i;
		if (vis[i]==1) se=i;
	}
	if (mn==-1) return puts("Impossible"),0;
	printf("%c%c%c\n",mn+'A',se+'A',(3-mn-se)+'A');
}