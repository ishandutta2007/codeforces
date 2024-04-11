#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,a,b) for(int i = (a); i >= (b); i--)
#define debug(x) cerr << #x << " = " << x << endl
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define inf 1e9
#define INF 0x7fffffff
#define ll long long
#define ull unsigned long long
#define sz(x) (int)x.size()
using namespace std;
typedef double db;
const int N = 1e2 + 7;
const int mod = 1e9 + 7;
int n,T,a[N],ans;
int calc(int x){
	int res = 0;
	rep(i,1,n) res += max(0,a[i] - x);
	return res;
}
int calc2(int x){
	int res = 0;
	rep(i,1,n) res += max(0,x - a[i]);
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		ans = inf;
		int l = 0,r = 1e7,L,R;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(calc(mid) <= calc2(mid)){
				R = mid;
				r = mid - 1;
			} 
			else l = mid + 1;
		}
		l = 0,r = 1e7;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(calc(mid) >= calc2(mid)){
				L = mid;
				l = mid + 1;
			} 
			else r = mid - 1;
		}
		// printf("%d %d\n",L,R);
		ans = min(ans,R - L);
		printf("%d\n",ans);
	}
	return 0;
}