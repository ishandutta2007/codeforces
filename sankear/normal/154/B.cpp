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

bool good[100100];
vector <int> v[100100];
set <int> s[100100];

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int ch = i + 1;
		for(int j = 2; j * j <= ch; j++){
			if(ch % j == 0){
				v[i].pb(j);
				while(ch % j == 0){
					ch /= j;
				}
			}
		}
		if(ch > 1){
			v[i].pb(ch);
		}
	}
	for(int i = 0; i < m; i++){
		char cmd;
		int num;
		scanf(" %c %d", &cmd, &num);
		num--;
		if(cmd == '+'){
			if(good[num]){
				printf("Already on\n");
				continue;
			}
			bool fl = false;
			for(int j = 0; j < (int)v[num].size(); j++){
				if(!s[v[num][j]].empty()){
					printf("Conflict with %d\n", *(s[v[num][j]].begin()) + 1);
					fl = true;
					break;
				}
			}
			if(!fl){
				printf("Success\n");
				for(int j = 0; j < (int)v[num].size(); j++){
					s[v[num][j]].insert(num);
				}
				good[num] = true;
			}
			continue;
		}
		if(!good[num]){
			printf("Already off\n");
			continue;
		}
		for(int j = 0; j < (int)v[num].size(); j++){
			s[v[num][j]].erase(s[v[num][j]].find(num));
		}
		good[num] = false;
		printf("Success\n");
	}
	return 0;
}