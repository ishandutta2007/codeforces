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

const int N=200000+19;

char s[N],t[N];
int P[N];
int n,res,m,l,r;

bool check(int x){
	int c=1;
	For(i,1,m+1){
		while (c<=n&&(s[c]!=t[i]||P[c]<=x)) c++;
		if (c>n) return 0;
		c++;
	}
	return 1;
}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	For(i,1,n+1) P[IN()]=i;
	l=0,r=n;
	while (l<=r){
		int mid=(l+r>>1);
		if (check(mid)) res=mid,l=mid+1;else r=mid-1;
	}
	printf("%d\n",res);
}