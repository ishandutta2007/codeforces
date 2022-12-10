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

const int N=1000+19;

vector<pii> res;
char s[N],t[N];
int A[26];
int n;

int main(){
	memset(A,-1,sizeof(A));
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	For(i,1,n+1){
		int x=s[i]-'a',y=t[i]-'a';
		if (~A[x]&&A[x]!=y||~A[y]&&A[y]!=x){
			puts("-1");
			return 0;
		} else{
			if (A[x]==-1&&x!=y) res.pb(mp(x,y));
			A[x]=y;
			A[y]=x;
		}
	}
	printf("%d\n",res.size());
	For(i,0,res.size()) printf("%c %c\n",res[i].fi+'a',res[i].se+'a');
}