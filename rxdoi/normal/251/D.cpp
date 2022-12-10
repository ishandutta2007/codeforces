#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

bitset<N> F[60],tmp;
int val[N],top[N],vis[N],v;
ll A[N],S;
int n,num;
vector<ll> V1,V2;

int main(){
	memset(top,-1,sizeof(top));
	n=IN();
	For(i,0,n){
		A[i]=IN();
		S^=A[i];
	}
	for (int t=63;~t;t--)
		if (!(S>>t&1)){
			tmp.reset();
			For(i,0,n) if (A[i]>>t&1) tmp[i]=1;
			v=1;
			For(i,0,num){
				if (tmp[top[i]]) tmp^=F[i],v^=val[i];
			}
			if (!tmp.count()) continue;
			for (int i=n-1;~i;i--)
				if (tmp[i]){
					top[num]=i;
					F[num]=tmp;
					val[num]=v;
					num++;
					break;
				}
		}
	for (int t=63;~t;t--)
		if (S>>t&1){
			tmp.reset();
			For(i,0,n) if (A[i]>>t&1) tmp[i]=1;
			v=0;
			For(i,0,num){
				if (tmp[top[i]]) tmp^=F[i],v^=val[i];
			}
			if (!tmp.count()) continue;
			for (int i=n-1;~i;i--)
				if (tmp[i]){
					top[num]=i;
					F[num]=tmp;
					val[num]=v;
					num++;
					break;
				}
		}
	for (int i=num-1;~i;i--)
		For(j,0,i){
			if (F[j][top[i]]) F[j]^=F[i],val[j]^=val[i];
		}
	For(i,0,num) if (val[i]) vis[top[i]]=1;
	For(i,0,n) printf("%d ",vis[i]?1:2);
	puts("");
}