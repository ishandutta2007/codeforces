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

typedef long long ll;

const ll mp = (ll)(1e9 + 7);

bool used[200];
char a[200][200];

int main(){
    //freopen("rifleman.in", "r", stdin);
    //freopen("rifleman.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	ll ans = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 26; j++){
			used[j] = false;
		}
		for(int j = 0; j < n; j++){
			used[a[j][i] - 'A'] = true;
		}
		int sz = 0;
		for(int j = 0; j < 26; j++){
			if(used[j]){
				sz++;
			}
		}
		ans = (ans * sz) % mp;
	}
	printf("%I64d\n", ans);
	return 0;
}