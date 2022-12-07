#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,a[2000222],pr[2000222], z[2000222];
long long u[2000222],ans,s[2000222], m[2000222];

void add(int x,int r){
	x++;
	while (x < 1000111){
		s[x] = (s[x] + r) % M;
		x = x + x - (x & (x - 1));
	}
}

int find(int x){
	x++;
	long long r=0;
	while (x){
		r = (r + s[x]) % M;
		x &= x - 1;
	}
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i], a[i] ++ ;
	for (int i=0;i<=1000111; i++) z[i] = -1;
	for (int i=n;i>0;i--)a[i]=a[i-1];
	a[0] = 0;
	n++;
	for (int i=0;i<n;i++){	
		pr[i]  = z[a[i]];
		z[a[i]] = i;
	}
	add(0,1);
	for (int i=1;i<n;i++){
		u[i] = find(a[i]);
		m[i] = u[i];
		if (pr[i] != -1) u[i] = (u[i] - m[pr[i]] + M) % M;
		u[i] = (u[i] * 1ll * (a[i] - 1)) %M;
		add(a[i], u[i]);
		ans = (ans + u[i]) % M;
	}
	cout << ans << endl;
	return 0;
}