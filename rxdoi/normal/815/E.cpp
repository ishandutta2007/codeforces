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
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

ll n,k;

ll cal(ll len,ll x){
	static map<ll,ll> M;
	if (!len) return 0;
	if (M.count(len)) return M[len];
	ll &res=M[len];
	res+=cal((len-1)/2,x);
	if ((len-1)/2==x) res++;
	res+=cal(len-1-(len-1)/2,x);
	return res;
}
ll gao(ll L,ll R,ll k,ll x){
	if (L>R) return 0;
	ll Mid=(L+R)/2;
	if (k<=cal(Mid-L,x)){
		return gao(L,Mid-1,k,x);
	} else{
		k-=cal(Mid-L,x);
	}
	if ((R-L)/2==x){
		if (k==1) return Mid;else k--;
	}
	return gao(Mid+1,R,k,x);
}
void Work(ll n,ll k){
	map<ll,ll,greater<ll> > M;
	map<ll,ll> now;
	now[n-2]=1;
	for (;;){
		map<ll,ll> nxt;
		for (auto x:now)
			if (x.fi){
				M[(x.fi-1)/2]+=x.se;
				nxt[(x.fi-1)/2]+=x.se;
				nxt[x.fi-1-(x.fi-1)/2]+=x.se;
			}
		now=nxt;
		if (now.empty()) break;
	}
	for (auto x:M){
		if (k<=x.se){
			cout<<gao(2,n-1,k,x.fi)<<endl;
			exit(0);
		} else{
			k-=x.se;
		}
	}
}

int main(){
	cin>>n>>k;
	if (k==1) return printf("1\n"),0;
	if (k==2) return cout<<n<<endl,0;
	Work(n,k-2);
}