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

const int N=75+3;
const int p=1e9+7;
const int oo=(1<<30)-1;

char s[N];
int f[N][1<<20],g[1<<20];
int n,res;

int calc(int l,int r){
	int res=0;
	For(i,l,r+1){
		res=(res*2+s[i]-'0');
		if (res>20) return oo;
	}
	return res;
}
bool check(int t){
	int mx=0;
	For(i,0,20) if (t>>i&1) mx=max(mx,i);
	For(i,0,mx+1) if (!(t>>i&1)) return 0;
	return 1;
}

int main(){
	n=IN();
	scanf("%s",s+1);
	f[0][0]=1;
	For(i,1,n+1){
		f[i][0]=1;
		for (int j=i;j>=1;j--){
			int val=calc(j,i)-1;
			if (val==-1||val>=20) continue;
			For(t,0,1<<20)
				if (f[j-1][t]){
					f[i][t|1<<val]=(f[i][t|1<<val]+f[j-1][t])%p;
				}
		}
		For(t,1,1<<20) g[t]=(g[t]+f[i][t])%p;
	}
	For(t,1,1<<20){
		if (check(t)) res=(res+g[t])%p;
	}
	printf("%d\n",res);
}