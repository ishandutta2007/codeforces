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

const int Top=10000000;

int go[Top][2],key[Top];
int x,len,tot,res;
char s[5],t[30];

void Insert(int v){
	x=0;
	len=strlen(t);
	For(i,0,len){
		int &u=go[x][(t[i]-'0')%2];
		if (!u) u=++tot;x=u;
	}
	key[x]+=v;
}
int calc(char *t){
	int len=strlen(t);x=0;
	For(i,0,len){
		int &u=go[x][t[i]-'0'];
		if (!u) return 0;x=u;
	}
	return key[x];
}

int main(){
	for (int Qc=IN();Qc--;){
		scanf("%s",s);
		if (s[0]=='+') scanf("%s",t),Insert(1);
		if (s[0]=='-') scanf("%s",t),Insert(-1);
		if (s[0]=='?'){
			scanf("%s",t+20);
			len=strlen(t+20);
			For(i,0,20) t[i]='0';
			res=0;len=strlen(t);
			For(i,0,len){
				res+=calc(t+i);
				if (t[i]=='1') break;
			}
			printf("%d\n",res);
		}
	}
}