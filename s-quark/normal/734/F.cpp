#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 212345;

int b[MAXN], c[MAXN];
int a[MAXN];
int ones[32];

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);

	ll sum = 0;
	for(i = 0; i < n; i++)
		sum += b[i] + c[i];
	if(sum % (2*n) != 0){
		printf("-1\n");
		exit(0);
	}

	sum /= 2*n;
	for(i = 0; i < n; i++){
		if((b[i]+c[i]-sum) % n != 0){
			printf("-1\n");
			exit(0);
		}
		a[i] = (b[i]+c[i]-sum) / n;
		if(a[i] < 0 || (ll)a[i]*n != b[i]+c[i]-sum){
			printf("-1\n");
			exit(0);
		}
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < 31; j++)
			ones[j] += a[i]>>j&1;
	}
//	for(j = 0; j < 31; j++)
//		printf("%d\n", ones[j]);

	for(i = 0; i < n; i++){
		ll t = 0;
		for(j = 0; j < 31; j++){
			if(a[i]>>j&1){
				t += (1LL<<j) * ones[j];
			}
		}
		if(t != b[i]){
			printf("-1\n");
			exit(0);
		}

		t = 0;
		for(j = 0; j < 31; j++){
			if(a[i]>>j&1){
				t += (1LL<<j) * n;
			}
			else{
				t += (1LL<<j) * ones[j];
			}
		}
		if(t != c[i]){
			printf("-1\n");
			exit(0);
		}
	}

	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	puts("");

	return 0;
}