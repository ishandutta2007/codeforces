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

const int N = 100;
ll a,b,m;

ll f[N];
ll B[N];
void proc() {
	scanf("%lld%lld%lld", &a, &b, &m);
	if(a==b) {
		printf("1 %lld\n", a);
		return;
	}


	ll L=a+1, R=a+m, k=0;
	while(L<=b) {
		if(b<=R) {
			ll d=b-L;
			for(int i=0; i<=k; i++) {
				f[i]=min(d/B[k-i], m-1);
				d-=B[k-i]*f[i];
			}

			ll sum=a;
			printf("%lld %lld ", k+2, a);
			for(int i=0; i<=k; i++) {
				printf("%lld ", sum+f[i]+1);
				sum=sum+sum+f[i]+1;
			}
			printf("\n");
			return;
		}
		L=L+L, R=R+R, k++;
	}
	printf("-1\n"); return;

}
int main(void){
	B[0]=1, B[1]=1; for(int i=2; i<60; i++) B[i]=B[i-1]+B[i-1];
	int tc;scanf("%d", &tc);
	while(tc--) proc();
}