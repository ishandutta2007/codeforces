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

const char val[5] = {'a', 'e', 'i', 'o', 'u'};

char cur[20000];
char *s[3000][5];

inline bool can(char ch){
	for(int i = 0; i < 5; i++){
		if(ch == val[i]){
			return true;
		}
	}
	return false;
}

inline bool check(char *s, char *t, int k){
	int n = strlen(s);
	int m = strlen(t);
	int cnt = 0, pos1 = -1, pos2 = -1;
	for(int i = n - 1; i >= 0; i--){
		if(can(s[i])){
			cnt++;
			if(cnt == k){
				pos1 = i;
				break;
			}
		}
	}
	cnt = 0;
	for(int i = m - 1; i >= 0; i--){
		if(can(t[i])){
			cnt++;
			if(cnt == k){
				pos2 = i;
				break;
			}
		}
	}
	if(pos1 == -1 || pos2 == -1 || n - pos1 != m - pos2){
		return false;
	}
	for(int i = pos1; i < n; i++){
		if(s[i] != t[pos2++]){
			return false;
		}
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			scanf("%s", cur);
			int len = strlen(cur);
			s[i][j] = (char*)malloc(sizeof(char) * (len + 1));
			strcpy(s[i][j], cur);
		}
	}
	bool fl = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int z = j + 1; z < 4; z++){
				if(!check(s[i][j], s[i][z], k)){
					fl = false;
					break;
				}
			}
			if(!fl){
				break;
			}
		}
		if(!fl){
			break;
		}
	}
	if(fl){
		printf("aaaa\n");
		return 0;
	}
	fl = true;
	for(int i = 0; i < n; i++){
		if(!check(s[i][0], s[i][1], k) || !check(s[i][2], s[i][3], k)){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("aabb\n");
		return 0;
	}
	fl = true;
	for(int i = 0; i < n; i++){
		if(!check(s[i][0], s[i][2], k) || !check(s[i][1], s[i][3], k)){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("abab\n");
		return 0;
	}
	fl = true;
	for(int i = 0; i < n; i++){
		if(!check(s[i][0], s[i][3], k) || !check(s[i][1], s[i][2], k)){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("abba\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}