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

const int MX = 105, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char in[5];

int x[MX], y[MX], xi, yi, z[MX];
bool u[MX];

int main(){
	int n, m, a;
	scanf("%d%d",&n,&m);
	
	rep(i,n){
		scanf("%s%d",in,&a);
		if(in[0] == 'A'){
			x[xi++] = a;
		} else {
			y[yi++] = a;
		}
	}
	sort(x,x+xi);
	sort(y,y+yi);
	
	rep(i,m) scanf("%d",&z[i]);
	sort(z,z+m);
	
	int ans = 0, s, sum;
	rrep(i,xi){
		if(i > m) break;
		s = m-i;
		bool bl = true;
		sum = 0;
		rep(j,i){
			if(x[j] > z[s+j]){
				bl = false;
				break;
			}
			sum += z[s+j]-x[j];
		}
		
		if(bl) ans = max(ans,sum);
	}
	
	s = 0;
	bool f = true;
	rep(i,yi){
		while(s < m && y[i] >= z[s]) s++;
		if(s == m){ f = false; break;}
		u[s] = true;
		s++;
	}
	
	if(f){
		sum = 0;
		s = 0;
		rep(i,xi){
			while(s < m && (u[s] || x[i] > z[s])) s++;
			if(s == m){ f = false; break;}
			sum -= x[i];
			s++;
		}
		rep(i,m) if(!u[i]) sum += z[i];
		if(f) ans = max(ans,sum);
	}
	
	printf("%d\n",ans);
	
	return 0;
}