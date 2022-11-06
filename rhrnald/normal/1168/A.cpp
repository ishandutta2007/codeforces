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
int x[N];
bool check(int d) {
	int prv=0;
	for(int i=0; i<n; i++) {
		if(x[i]<=prv) {
			if(x[i]+d<prv) return false;
			continue;
		}
		if(x[i]+d>=m+prv) continue;
		prv=x[i];
	}
	return true;
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", x+i);

	int l=-1, r=m-1;
	while(r-l>1) {
		int mid=(r+l)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d", r);
}