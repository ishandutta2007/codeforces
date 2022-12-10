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
#define fir first
#define sec second

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

struct Edge{
	int x,y,z,id;
	bool operator < (const Edge &B) const {return z>B.z;}
} E[N*N];
int fa[N],val[N];
int n,m,Qc,l,r,Ans;

int getf(int x){
	if (fa[x]==x) return x;
	int f=fa[x];
	fa[x]=getf(f);
	val[x]^=val[f];
	return fa[x];
}

int main(){
	n=IN(),m=IN(),Qc=IN();
	For(i,1,m+1){
		E[i]=(Edge){IN(),IN(),IN(),i};
	}
	sort(E+1,E+m+1);
	while (Qc--){
		For(i,1,n+1){
			fa[i]=i;
			val[i]=0;
		}
		l=IN(),r=IN();
		Ans=-1;
		For(i,1,m+1)
			if (l<=E[i].id&&E[i].id<=r){
				int x=E[i].x,y=E[i].y,d;
				getf(x),getf(y);
				d=val[x]^val[y];
				if (fa[x]==fa[y]){
					if (d==0){
						Ans=E[i].z;
						break;
					}
				} else{
					x=getf(x);
					fa[x]=getf(y);
					val[x]=d^1;
				}
			}
		printf("%d\n",Ans);
	}
}