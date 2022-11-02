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

const int inf = (int)1e9;

int x[100100], t[100100], stack[100100];
ll ans[100100], res[100100];

int main(){
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &t[i], &x[i]);
	}
	int k = 0;
	ll time = 0;
	map <int, int> mem;
	for(int i = 0; i < n; i++){
		mem[x[i]]++;
		stack[k++] = i;
		if(k == m || i == n - 1){
			time = max(time, (ll)t[i]);
			int last = 0;
			for(map <int, int> :: iterator it = mem.begin(); it != mem.end(); it++){
				time += it->first - last;
				last = it->first;
				res[it->first] = time;
				time += 1 + it->second / 2;
			}
			time += last;
			for(int j = 0; j < k; j++){
				mem[x[stack[j]]] = 0;
				ans[stack[j]] = res[x[stack[j]]];
			}
			k = 0;
			mem.clear();
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%I64d", ans[i]);
	}
	return 0;
}