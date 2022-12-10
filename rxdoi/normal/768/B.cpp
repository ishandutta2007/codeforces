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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef pair<ll,ll> pll;
ll n,l,r;
map<ll,pll> M;

pll calc(ll n){
	if (M.count(n)) return M[n];
	if (n==0) return M[n]=mp(1,0);
	if (n==1) return M[n]=mp(1,1);
	pll A=calc(n/2),B=calc(n%2);
	M[n]=mp(2*A.fi+B.fi,2*A.se+B.se);
	return M[n];
}
ll F(ll n,ll k){
	pll A=calc(n/2),B=calc(n%2);
	if (n==0||n==1) return n&&k;
	if (k<=A.fi) return F(n/2,k);
	k-=A.fi;
	if (k<=B.fi) return A.se+F(n%2,k);
	k-=B.fi;
	return A.se+B.se+F(n/2,k);
}

int main(){
	cin>>n>>l>>r;
	cout<<F(n,r)-F(n,l-1)<<endl;
}