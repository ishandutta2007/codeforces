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
int n;
int x[N], y[N];

int a,b,c,d,p,q;
int main(void){
	scanf("%d%d%d", &n, &p, &q);
	for(int i=0; i<n; i++) scanf("%d%d", x+i, y+i);

	for(int i=0; i<n; i++) if(x[i]>p) a++;
	for(int i=0; i<n; i++) if(x[i]<p) b++;
	for(int i=0; i<n; i++) if(y[i]>q) c++;
	for(int i=0; i<n; i++) if(y[i]<q) d++;

	int M=max({a,b,c,d});
	printf("%d\n", M);
	if(M==a) {
		p++;
	} else if(M==b) {
		p--;
	} else if(M==c) {
		q++;
	} else {
		q--;
	}
	printf("%d %d", p,q);
}