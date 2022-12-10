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

const int N=10000+19;
const ll oo=1ll<<60;

ll f[2][N],res=oo;
int p[N],s[N];
int n,c,t;

int main(){
	n=IN(),c=IN();
	For(i,1,n+1) p[i]=IN();
	For(i,1,n+1) s[i]=IN();
	For(i,0,n+1) f[t][i]=oo;
	f[t][0]=0;
	For(i,1,n+1){
		t^=1;
		For(j,0,n+1){
			f[t][j]=f[t^1][j]+p[i]+1ll*j*c;
			if (j) f[t][j]=min(f[t][j],f[t^1][j-1]+s[i]);
		}
	}
	For(i,0,n+1) res=min(res,f[t][i]);
	cout<<res<<endl;
}