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

const int N=3e5+19;
const int oo=(1<<30)-1;

struct seg{
	ll l,r;
	int id;
	bool operator < (const seg &B) const {return l<B.l;}
} A[N];
int n,k,st,ed;
ll l,r,res;

multiset<ll> S;

bool check(ll x){
	S.clear();
	For(i,1,n+1)
		if (A[i].r-A[i].l>=x){
			S.insert(A[i].r);
			while (!S.empty()&&*S.begin()-A[i].l<x) S.erase(S.begin());
			if (S.size()>=k){
				st=A[i].l;
				ed=A[i].l+x;
				return 1;
			}
		}
	st=oo;
	ed=-oo;
	return 0;
}

int main(){
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=(seg){IN(),IN(),i};
	sort(A+1,A+n+1);
	l=0,r=int(2e9);res=-1;
	while (l<=r){
		ll mid=(l+r>>1);
		if (check(mid)) res=mid,l=mid+1;else r=mid-1;
	}
	cout<<res+1<<endl;
	check(res);
	For(i,1,n+1)
		if (A[i].l<=st&&ed<=A[i].r){
			printf("%d ",A[i].id);
			if (--k==0) break;
		}
	puts("");
}