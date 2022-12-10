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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

map<ll,ll> val;
int Qc,dx,dy,v;
ll x,y,res;

int dep(ll x){
	int res=0;
	while (x!=1) x/=2,res++;
	return res;
}

int main(){
	Qc=IN();
	while (Qc--){
		if (IN()==1){
			x=IN(),y=IN();v=IN();
			dx=dep(x),dy=dep(y);
			while (x!=y){
				if (dx>dy){
					val[x]+=v,x/=2,dx--;
				} else{
					val[y]+=v,y/=2,dy--;
				}
			}
		} else{
			x=IN(),y=IN();res=0;
			dx=dep(x),dy=dep(y);
			while (x!=y){
				if (dx>dy){
					res+=val[x],x/=2,dx--;
				} else{
					res+=val[y],y/=2,dy--;
				}
			}
			printf("%I64d\n",res);
		}
	}
}