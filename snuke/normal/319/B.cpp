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
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int a[MX], t[MX];
int e[2][MX], ei[2], o, p;

int main(){
	int n;
	scanf("%d",&n);
	rrep(i,n){ scanf("%d",&a[i]); t[i-1] = i; e[0][ei[0]++] = n-i;}
	a[0] = -1; t[n] = -1;
	o = 0; p = 1;
	int ans = -1, v;
	while(ei[o]){
		ei[p] = 0;
		rep(i,ei[o]){
			v = e[o][i];
			if(a[v] == -1 || t[v] == -1) continue;
			if(a[v] > a[t[v]]){
				a[t[v]] = -1;
				e[p][ei[p]++] = v;
				t[v] = t[t[v]];
			}
		}
		ans++;
		swap(o,p);
	}
	
	cout << ans << endl;
	
	return 0;
}