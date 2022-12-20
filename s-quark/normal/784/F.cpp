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

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 1e9+7;

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	int a[100];
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		//a[i] += 1;
	}
	sort(a, a+n);
	while(clock() < 1200)
		i++;
	for(i = 0; i < n-1; i++)
		printf("%d ", a[i]);
	printf("%d \n", a[n-1]);
	return 0;
}