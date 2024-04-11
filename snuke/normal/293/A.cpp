#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 2000005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int x[MX], a[4];

int main(){
	int n, p = 0, q = 0;
	scanf("%d",&n); n <<= 1;
	char c;
	rep(i,n){
		scanf(" %c",&c);
		x[i] = c-'0';
	}
	rep(i,n){
		scanf(" %c",&c);
		x[i] += 2*(c-'0');
	}
	//rep(i,n) printf("%d ",x[i]);
	
	rep(i,n){
		a[x[i]]++;
	}
	
	p = (a[3]+1)/2+(a[1]-a[3]%2+1)/2;
	q = a[3]/2+(a[2]+(a[1]+a[3])%2)/2;
	//printf("%d %d\n",p,q); printf("%d %d\n",x[3],x[1]);
	if(p > q) puts("First");
	if(p < q) puts("Second");
	if(p == q)puts("Draw");
	
	return 0;
}