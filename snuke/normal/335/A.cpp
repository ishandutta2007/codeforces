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
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int a[256], n;

bool f(int c){
	int x = 0;
	rep(i,256){
		x += (a[i]-1+c)/c;
	}
	return x <= n;
}

int main(){
	string s;
	cin >> s >> n;
	
	rep(i,s.size()){
		a[s[i]]++;
	}
	
	int l = 0, r = 1005, c;
	while(l+1<r){
		c = (l+r)/2;
		if(f(c)) r = c; else l = c;
	}
	c = r;
	
	if(r == 1005){
		puts("-1");
	} else {
		printf("%d\n",r);
		rep(i,256){
			rep(j,(a[i]-1+c)/c){
				printf("%c",i);
				n--;
			}
		}
		while(n--) printf("a");
		puts("");
	}
	
	return 0;
}