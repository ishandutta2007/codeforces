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

const int N = 1000001;
int n,m;

int pow(int x, int num) {
	int ret=1;
	while(num--) ret*=x;
	return ret;
}

int p[N];
int q[N];
ll f(int a, int b) {
	if(a<0 || b<0) return 0;
	for(int i=0; i<30; i++) p[i]=a&1, a>>=1;
	for(int i=0; i<30; i++) q[i]=b&1, b>>=1;
	
	ll z=1, x=0, y=0, w=0;
	for(int i=29; i>=0; i--) {
		ll nx, ny, nz, nw;
		if(p[i] && q[i]) {
			nz=0;
			nx=x+z;
			ny=y+z;
			nw=x+x+y+y+z+w+w+w;
		} else if(p[i]) {
			nz=z;
			nx=x+x+z;
			ny=y;
			nw=y+y+w+w+w;
		} else if(q[i]) {
			nz=z;
			nx=x;
			ny=y+y+z;
			nw=x+x+w+w+w;
		} else {
			nz=z;
			nx=x+x;
			ny=y+y;
			nw=w+w+w;
		}
		
		z=nz, x=nx, y=ny, w=nw;
	}
	return z+x+y+w;
}
void proc() {
	scanf("%d%d", &m, &n);
	printf("%lld\n", f(n,n)-f(n,m-1)-f(m-1,n)+f(m-1,m-1));
	return;
/*	int l=n, r=m;
	for(int i=0; i<30; i++) x[i]=0, y[i]=0;
	for(int i=0; i<30; i++) x[i]=n&1, n>>=1;
	for(int i=0; i<30; i++) y[i]=m&1, m>>=1;

	int sx=29, sy=29;
	while(sx>=0 && !x[sx]) sx--; sx++;
	while(sy>=0 && !y[sy]) sy--; sy++;
	if(sy==0) {
		printf("1\n");
		return;
	}
	ll ans=0;
	for(int k=sx; k<sy; k++) {
		int a=1, fx=0, fy=0, b=0;
		if(k<sy-1) a=0, fy=1;

		for(int i=k-1; i>=0; i--) {
			if(x[i] && y[i]) {
				a=0;
				fx=fx;
				fy=a+fy+fy;
				b=fx+fx+b+b+b;
			} else if(x[i]) {
				a=a;
				fx=fx+fx;
				fy=fy;
				b=b+b+b;
			} else if(y[i]) {
				a=a;
				fx=fx;
				fy=fy;
				b=a+a+fx+fx+fy+fy;
			} else {
				a=a;
				fx=a+fx+fx;
				fy=fy+fy;
				b=fy+b+b+b;
			}
		}
		ans+=a+fx+fy+b;
	}
	ans=ans+ans;
	if(!sx) ans++;
	cout << ans << endl;*/
}
int main(void){
	int tc;
	scanf("%d", &tc);
	while(tc--) proc();
}