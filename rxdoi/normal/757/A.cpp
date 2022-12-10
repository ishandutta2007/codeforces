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

const int N=1e5+19;
const int oo=(1<<30)-1;

char s[N];
int cnt[128];
int n,res=oo;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n+1) cnt[s[i]]++;
	res=min(res,cnt['B']);
	res=min(res,cnt['u']/2);
	res=min(res,cnt['l']);
	res=min(res,cnt['b']);
	res=min(res,cnt['a']/2);
	res=min(res,cnt['s']);
	res=min(res,cnt['r']);
	printf("%d\n",res);
}