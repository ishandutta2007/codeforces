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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

ll A[N];
int n,l,r;

bool check(int T){
	map<ll,int> M,vis;
	multiset<ll> S;
	For(i,0,60) vis[1ll<<i]=1;
	For(i,1,n+1){
		M[A[i]]++;
		if (!vis.count(A[i])) S.insert(A[i]);
	}
	int tmp=M[1]-T;
	For(j,0,tmp){
		S.insert(1),M[1]--;
	}
	For(i,1,60){
		int tmp=M[1ll<<i]-M[1ll<<i-1];
		For(j,0,tmp){
			S.insert(1ll<<i),M[1ll<<i]--;
		}
	}
	int res=0;
	for (;;){
		if (!M[1]) break;
		ll x=1;
		for (;;){
			M[x]--;
			x*=2;
			if (!M[x]) break;
		}
		if (S.upper_bound(x)!=S.begin()){
			S.erase(--S.upper_bound(x));
		}
		res++;
	}
	For(i,0,60) if (M[1ll<<i]) return 0;
	if (!S.empty()) return 0;
	return 1;
}
int calmax(){
	map<ll,int> M,vis;
	multiset<ll> S;
	For(i,0,60) vis[1ll<<i]=1;
	For(i,1,n+1){
		M[A[i]]++;
		if (!vis.count(A[i])) S.insert(A[i]);
	}
	For(i,1,60){
		int tmp=M[1ll<<i]-M[1ll<<i-1];
		For(j,0,tmp){
			S.insert(1ll<<i),M[1ll<<i]--;
		}
	}
	int res=0;
	for (;;){
		if (!M[1]) break;
		ll x=1;
		for (;;){
			M[x]--;
			x*=2;
			if (!M[x]) break;
		}
		if (S.upper_bound(x)!=S.begin()){
			S.erase(--S.upper_bound(x));
		}
		res++;
	}
	For(i,0,60) if (M[1ll<<i]) return -1;
	if (!S.empty()) return -1;
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	r=calmax();
	if (r==-1) return puts("-1"),0;
	int L=1,R=r;
	while (L<=R){
		int mid=(L+R)/2;
		if (check(mid)) R=mid-1;else L=mid+1;
	}
	For(i,R+1,r+1) printf("%d ",i);
	puts("");
}