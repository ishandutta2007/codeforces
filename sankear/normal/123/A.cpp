#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

int k;
int used[30];
bool good[2000];
int use[2000], first[2000], sz[2000];
int go[2000100], next[2000100];
char s[2000];

inline void add(int a, int b){
	go[++k] = b;
	next[k] = first[a];
	first[a] = k;
}

void dfs(int a, int b){
	use[a] = b;
	sz[b]++;
	for(int i = first[a]; i > 0; i = next[i]){
		if(use[go[i]] == -1){
			dfs(go[i], b);
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		used[s[i] - 'a']++;
	}
	k = 0;
	for(int i = 2; i <= n; i++){
		bool fl = true;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				fl = false;
				break;
			}
		}
		if(fl){
			for(int j = 1; j <= n / i; j++){
				add(i - 1, j * i - 1);
				add(j * i - 1, i - 1);
			}
		}
	}
	for(int i = 0; i < n; i++){
		use[i] = -1;
	}
	for(int i = 0; i < n; i++){
		if(use[i] == -1){
			good[i] = true;
			dfs(i, i);
		}
	}
	for(int i = 0; i < n; i++){
		int need = -1;
		for(int j = 0; j < n; j++){
			if(good[j]){
				if(need == -1 || sz[j] > sz[need]){
					need = j;
				}
			}
		}
		if(need != -1){
				int best = -1;
				for(int j = 0; j < 26; j++){
					if(used[j] >= sz[need] && (best == -1 || used[j] < used[best])){
						best = j;
					}
				}
				if(best != -1){
					for(int j = 0; j < n; j++){
						if(use[j] == need){
							s[j] = 'a' + best;
						}
					}
					used[best] -= sz[need];
					good[need] = false;
				}
		}
	}
	for(int i = 0; i < n; i++){
		if(good[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n%s\n", s);
	return 0;
}