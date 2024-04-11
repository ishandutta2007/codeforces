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

const int N = 3000;
int n,m;
int x[N];
int cnt[N];
bool check(int val) {
	cnt[0]=0;
	int ans=n-1;
	for(int i=1; i<n; i++) {
		cnt[i]=i;
		for(int j=i-1; j>=0; j--) {
			if(abs(x[j]-x[i])<=1ll*val*(i-j)) cnt[i]=min(cnt[i], cnt[j]+i-j-1);
		}
		ans=min(ans,cnt[i]+n-i-1);
	}
	return ans<=m;
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	if(n<=1 || m==n) {printf("0"); return 0;}
	ll l=-1, r=INF+INF;
	while(r-l>1) {
		ll mid=(r+l)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d", r);
}