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
#define lf else if

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

struct Edge{
	int x,y,z;
	bool operator < (const Edge &B) const {return z>B.z;}
} E[N];
int fa[N],cnt[N],sz[N];
int n,m,x,y;
ll ans;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y){
		fa[x]=y;
		cnt[y]+=cnt[x]+1;
		sz[y]+=sz[x];
	}
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1) E[i]=(Edge){IN(),IN(),IN()};
	sort(E+1,E+m+1);
	For(i,1,n+1) fa[i]=i,cnt[i]=0,sz[i]=1;
	For(i,1,m+1){
		x=getf(E[i].x),y=getf(E[i].y);
		if (x!=y){
			if (cnt[x]==sz[x]&&cnt[y]==sz[y]) continue;
			Union(x,y);
			ans+=E[i].z;
		} else{
			if (cnt[x]<sz[x]){
				cnt[x]++;
				ans+=E[i].z;
			}
		}
	}
	cout<<ans<<endl;
}