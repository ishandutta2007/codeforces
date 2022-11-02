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
#define mp make_pair

typedef pair <int, int> pii;

pii a[100100], b[100100];

int main(){
	//freopen("country.in", "r", stdin);
	//freopen("country.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + m);
	int j = 0;
	vector <pii> ans;
	for(int i = 0; i < m; i++){
		while(j < n && a[j].first + y < b[i].first){
			j++;
		}
		if(j < n && a[j].first - x <= b[i].first && b[i].first <= a[j].first + y){
			ans.pb(mp(a[j].second, b[i].second));
			j++;
		}
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < (int)ans.size(); i++){
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	return 0;
}