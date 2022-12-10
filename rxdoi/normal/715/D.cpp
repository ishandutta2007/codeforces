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

ll T;
int n,m,A[100];
vector<pair<pii,pii> > V;

int main(){
	scanf("%I64d",&T);
	n=4,m=4;
	for (;T;T/=6) A[++*A]=T%6;
	switch (A[*A]){
		case 0:{
			V.pb(mp(mp(4,3),mp(4,4)));
			V.pb(mp(mp(3,4),mp(4,4)));
			break;
		}
		case 1:{
			V.pb(mp(mp(2,3),mp(2,4)));
			V.pb(mp(mp(3,3),mp(3,4)));
			V.pb(mp(mp(4,3),mp(4,4)));
			break;
		}
		case 2:{
			V.pb(mp(mp(3,2),mp(4,2)));
			V.pb(mp(mp(3,3),mp(4,3)));
			V.pb(mp(mp(2,3),mp(2,4)));
			V.pb(mp(mp(3,3),mp(3,4)));
			break;
		}
		case 3:{
			V.pb(mp(mp(2,2),mp(3,2)));
			V.pb(mp(mp(2,3),mp(3,3)));
			V.pb(mp(mp(2,4),mp(3,4)));
			V.pb(mp(mp(2,3),mp(2,4)));
			V.pb(mp(mp(4,1),mp(4,2)));
			break;
		}
		case 4:{
			V.pb(mp(mp(2,2),mp(3,2)));
			V.pb(mp(mp(2,3),mp(3,3)));
			V.pb(mp(mp(2,3),mp(2,4)));
			V.pb(mp(mp(4,1),mp(4,2)));
			break;
		}
		case 5:{
			V.pb(mp(mp(2,2),mp(3,2)));
			V.pb(mp(mp(2,3),mp(3,3)));
			V.pb(mp(mp(2,3),mp(2,4)));
			break;
		}
	}
	for (int i=(*A)-1;i;i--){
		n+=2,m+=2;
		
		V.pb(mp(mp(n-2,m-4),mp(n-1,m-4)));
		V.pb(mp(mp(n-2,m-3),mp(n-1,m-3)));
		V.pb(mp(mp(n-1,m-5),mp(n,m-5)));
		V.pb(mp(mp(n-1,m-4),mp(n,m-4)));
		
		V.pb(mp(mp(n-5,m-1),mp(n-5,m)));
		V.pb(mp(mp(n-4,m-1),mp(n-4,m)));
		V.pb(mp(mp(n-4,m-2),mp(n-4,m-1)));
		V.pb(mp(mp(n-3,m-2),mp(n-3,m-1)));
		V.pb(mp(mp(n-3,m-1),mp(n-2,m-1)));

		switch (A[i]){
			case 0:{
				V.pb(mp(mp(n,m-3),mp(n,m-2)));
				V.pb(mp(mp(n-1,m-3),mp(n-1,m-2)));
				V.pb(mp(mp(n-3,m),mp(n-2,m)));
				break;
			}
			case 1:{
				V.pb(mp(mp(n,m-3),mp(n,m-2)));
				V.pb(mp(mp(n-1,m-3),mp(n-1,m-2)));
				break;
			}
			case 2:{
				V.pb(mp(mp(n-1,m-3),mp(n-1,m-2)));
				break;
			}
			case 3:{
				V.pb(mp(mp(n,m-3),mp(n,m-2)));
				V.pb(mp(mp(n-3,m),mp(n-2,m)));
				break;
			}
			case 4:{
				V.pb(mp(mp(n,m-3),mp(n,m-2)));
				break;
			}
			case 5:{
				break;
			}
		}
	}
	printf("%d %d\n",n,m);
	printf("%d\n",V.size());
	For(i,0,V.size()){
		printf("%d %d %d %d\n",V[i].fi.fi,V[i].fi.se,V[i].se.fi,V[i].se.se);
	}
}