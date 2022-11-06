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
bool check(int x) {
	vector<int> v;
	while(x) v.push_back(x%10), x/=10;
	sort(all(v));
	return unique(all(v)) == v.end();
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=n; i<=m; i++) {
		if(check(i)) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
}