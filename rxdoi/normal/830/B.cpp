#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<string>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
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
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

int A[N],id[N],C[N];
int n,x;
ll ans;

void Add(int x,int v){
	for (;x<=n;x+=x&-x) C[x]+=v;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=C[x];
	return res;
}

bool cmp1(int x,int y){
	return A[x]<A[y];
}
bool cmp2(int i,int j){
	return (i-x+n)%n<(j-x+n)%n;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) id[i]=i;
	For(i,1,n+1) Add(i,1);
	sort(id+1,id+n+1,cmp1);
	x=1;
	for (int l=1,r;l<=n;l=r+1){
		for (r=l;r+1<=n&&A[id[r+1]]==A[id[l]];r++);
		sort(id+l,id+r+1,cmp2);
		x=id[r];
	}
	x=0;
	For(i,1,n+1){
		if (x<id[i]){
			ans+=Qry(id[i])-Qry(x);
		} else{
			ans+=Qry(n)-Qry(x);
			ans+=Qry(id[i]);
		}
		x=id[i];
		Add(x,-1);
	}
	cout<<ans<<endl;
}