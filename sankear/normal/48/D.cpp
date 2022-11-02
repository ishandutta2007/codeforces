#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back
#define ppb pop_back

typedef pair <int, int> pii;

vector <int> v[100100];
int ans[100100], res[100100];
pii p[100100];

int main(){
	//freopen("contest.out", "r", stdin);
	//freopen("contest.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	sort(p, p + n);
	for(int i = 0; i < n; i++){
		v[0].pb(i);
	}
	for(int i = 0; i < n; i++){
		int cur = p[i].first;
		if(v[cur - 1].size() == 0){
			printf("-1\n");
			return 0;
		}
		ans[p[i].second] = v[cur - 1][v[cur - 1].size() - 1];
		v[cur - 1].ppb();
		v[cur].pb(ans[p[i].second]);
	}
	for(int i = 0; i < n; i++){
		res[i] = ans[i];
	}
	sort(res, res + n);
	int k = unique(res, res + n) - res;
	printf("%d\n", k);
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lower_bound(res, res + k, ans[i]) - res + 1);
	}
	printf("\n");
	return 0;
}