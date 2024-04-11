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
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define mp make_pair

typedef pair <int, int> pii;
typedef long long ll;

char s[2020];
pii p[4000400];

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	int sz = 0;
	for(int i = 0; i < n; i++){
		int j = i, z = i;
		while(j >= 0 && z < n && s[j] == s[z]){
			p[sz++] = mp(j--, z++);
		}
		j = i, z = i + 1;
		while(j >= 0 && z < n && s[j] == s[z]){
			p[sz++] = mp(j--, z++);
		}
	}
	sort(p, p + sz);
	ll ans = 0;
	for(int i = 0; i < sz; i++){
		int res = -1, l = 0, r = sz - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].first > p[i].second){
				res = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		if(res != -1){
			ans += sz - res;
		}
	}
	cout << ans << endl;
	return 0;
}