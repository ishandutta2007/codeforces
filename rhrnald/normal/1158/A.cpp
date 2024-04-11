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

int a[N];
int b[N];

int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) scanf("%d", a+i);
	for(int i=0;i<m;i++) scanf("%d", b+i);

	sort(a, a+n);
	sort(b, b+m);
	if(b[0]<a[n-1]) {printf("-1"); return 0;}

	ll sum=0, sum2=0;
	for(int i=0; i<n; i++) sum+=a[i];
	for(int i=0; i<m; i++) sum2+=b[i]-a[n-1];
	if(b[0]>a[n-1]) sum2+=a[n-1]-a[n-2];
	cout << sum*m+sum2;
}