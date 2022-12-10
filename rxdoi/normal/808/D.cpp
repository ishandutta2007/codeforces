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

const int N=100000+19;

ll pre[N],suf[N];
int A[N];
int n;
map<ll,int> M;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+A[i];
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+A[i];
	For(i,1,n) if (pre[i]==suf[i+1]) return puts("YES"),0;
	for (int i=1;i<=n;i++){
		M[A[i]]++;
		if (pre[i]>suf[i+1]&&(pre[i]-suf[i+1])%2==0&&M.count((pre[i]-suf[i+1])/2)) return puts("YES"),0;
	}
	M.clear();
	for (int i=n;i>=1;i--){
		M[A[i]]++;
		if (suf[i]>pre[i-1]&&(suf[i]-pre[i-1])%2==0&&M.count((suf[i]-pre[i-1])/2)) return puts("YES"),0;
	}
	puts("NO");
}