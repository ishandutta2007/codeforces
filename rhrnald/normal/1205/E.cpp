#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 200001;
const int MOD =1000000007;
#define mult(x,y) ((int)(1ll*(x)*(y)%MOD))
int rev(int x) {
	if(x==1) return 1;
	x=x%MOD; if(x<0) x+=MOD;
	return mult(mult((MOD-1),(MOD/x)),rev(MOD%x));
}

int n,k;

int pw[N];
int phi[N];

int mp[N];
void make() {
	pw[0]=1;
	for(int i=1; i<=n; i++) pw[i]=mult(pw[i-1],k);

	for(int i=2; i*i<N; i++) {
		if(mp[i]) continue;
		for(int j=i; j<N; j+=i) {
			if(!mp[j]) mp[j]=i;
		}
	}
	for(int i=2; i<N; i++) if(!mp[i]) mp[i]=i;
	
	phi[1]=1;
	for(int i=2; i<N; i++) {
		int t=i/mp[i];
		if(t%mp[i]) phi[i]=mult(phi[i/mp[i]], mp[i]-1);
		else phi[i]=mult(phi[i/mp[i]], mp[i]);
	}
}

void findD(int x, vector<int> &v) {
	v.clear(); v.push_back(1);

	while(x>1) {
		int p=mp[x], cnt=0;
		while(!(x%p)) x/=p, cnt++;

		int s=sz(v);
		for(int i=0; i<s; i++) {
			int cur=v[i];
			for(int j=0; j<cnt; j++) {
				cur=mult(cur, p);
				v.push_back(cur);
			}
		}
	}
	sort(all(v));
}
void count(int l, int r, vector<int> &v, vector<int> &c) {
	c.resize(sz(v));
	for(int i=0; i<sz(v); i++) {
		int d=v[i];
		c[i]=r/d-(l-1)/d;
	}
	for(int i=sz(v)-1; i>=0; i--) {
		for(int j=i+1; j<sz(v); j++) {
			if(!(v[j]%v[i])) c[i]-=c[j];
		}
	}
}

int main(void){
	scanf("%d%d", &n, &k);
	make();
	ll ans=0;
	for(int i=1; i<=n-1; i++) ans+=pw[i];
	for(int xy=2; xy<=n; xy++) {
		vector<int> v;
		findD(xy, v);
		ll temp=0;
		for(int d : v) temp+=1ll*phi[xy/d]/2*2*pw[d];
		ans+=temp%MOD;
	}
	for(int k=1; k<n; k++) {
		//x+y=n+k
		vector<int> v,c;
		findD(n+k,v);
		count(k+1,n-1,v,c);
		ll temp=0;
		for(int i=0; i<sz(v); i++) {
			int d=v[i]; int cnt=c[i];
			if(d>k) temp+=1ll*pw[d]*cnt;
			else temp+=1ll*pw[k]*cnt;
		}
		if(!((n+k)%2)) temp-=1ll*pw[(n+k)/2];
		ans+=temp%MOD;
	}
	ans%=MOD;
	ans=mult(ans, rev(pw[n]));
	cout << ans;

}