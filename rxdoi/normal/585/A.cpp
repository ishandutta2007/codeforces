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

const int N=4000+19;

Vi V;
ll v[N],d[N],p[N],a,b;
int n;

int main(){
	n=IN();
	For(i,1,n+1){
		v[i]=IN();
		d[i]=IN();
		p[i]=IN();
	}
	For(i,1,n+1)
		if (p[i]>=0){
			V.pb(i);
			a=0;b=v[i];
			for (int j=i+1;j<=n;j++)
				if (p[j]>=0){
					p[j]-=a+b;
					if (b) b--;
					if (p[j]<0) a+=d[j];
				}
		}
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}