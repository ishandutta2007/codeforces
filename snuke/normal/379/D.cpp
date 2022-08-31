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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 55, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

ll a[MX], b[MX], s[MX], t[MX];
ll c[MX][2][2];
ll sa, sb, sc[2][2];
int d[2][2];

string mk(int n, int p, int q, int r){
	string l;
	rep(i,n) l += 'B';
	if(p == 0) l[0] = 'A';
	if(p == 1) l[0] = 'C';
	if(q == 0) l[n-1] = 'A';
	if(q == 1) l[n-1] = 'C';
	int u = 0; if(p!=0) u = 1;
	while(r){
		l[u++] = 'A';
		l[u++] = 'C';
		r--;
	}
	return l;
}

int main(){
	int n, m, k, x;
	cin >> k >> x >> n >> m;
	
	a[0] = 1; b[0] = 0; s[0] = t[0] = 0;
	a[1] = 0; b[1] = 1; s[1] = t[1] = 1;
	
	for(int i = 2; i < k; i++){
		s[i] = s[i-2];
		t[i] = t[i-1];
		a[i] = a[i-1]+a[i-2];
		b[i] = b[i-1]+b[i-2];
		rep(j,2)rep(h,2){
			c[i][j][h] = c[i-1][j][h]+c[i-2][j][h];
		}
		c[i][s[i-1]][t[i-2]]++;
	}
	//rep(i,k) sa += a[i];
	//rep(i,k) sb += b[i];
	sa = a[k-1];
	sb = b[k-1];
	//rep(i,k)rep(j,2)rep(h,2) sc[j][h] += c[i][j][h];
	rep(j,2)rep(h,2) sc[j][h] = c[k-1][j][h];
	//rep(i,k-1) sc[s[i+1]][t[i]]++;
	
	//rep(j,2)rep(h,2) cout << sc[j][h] << " ";
	//cout << " " << sa << " " << sb << endl;
	
	rep(s1,3)rep(s2,3)rep(t1,3)rep(t2,3)rep(c1,n)rep(c2,m){
		if(s1!=t1 && n == 1) continue;
		if(s2!=t2 && m == 1) continue;
		d[0][0] = (s1==1&&t1==0);
		d[0][1] = (s1==1&&t2==0);
		d[1][0] = (s2==1&&t1==0);
		d[1][1] = (s2==1&&t2==0);
		ll sum = 0;
		rep(j,2)rep(h,2) sum += sc[j][h]*d[j][h];
		if(sum > x) continue;
		
		int mn = 0, mx = 0;
		if(n == 2 && s1==0 && t1==1) mn = 1;
		if(s1==0) mx = (n-1)/2+((n%2==0)&&t1==1?1:0);
		else mx = (n-2)/2+((n&1)&&t1==1?1:0);
		if(c1 < mn || c1 > mx) continue;
		
		if(m == 2 && s2==0 && t2==1) mn = 1; else mn = 0;
		if(s2==0) mx = (m-1)/2+((m%2==0)&&t2==1?1:0);
		else mx = (m-2)/2+((m&1)&&t2==1?1:0);
		if(c2 < mn || c2 > mx) continue;
		
		if(sum+sa*c1+sb*c2 == x){
			cout << mk(n,s1,t1,c1) << endl;
			cout << mk(m,s2,t2,c2) << endl;
			return 0;
		}
	}
	
	puts("Happy new year!");
	
	return 0;
}