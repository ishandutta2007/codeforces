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

bool can[100100];
int look[100100], sz1[100100], sz2[100100];

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int all = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &look[i]);
		if(look[i] < 0){
			all++;
			sz2[-look[i] - 1]++;
		}
		else{
			sz1[look[i] - 1]++;
		}
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		if(sz1[i] + all - sz2[i] == m){
			can[i] = true;
			sz++;
		}
	}
	for(int i = 0; i < n; i++){
		bool need = false;
		if(look[i] > 0){
			need = true;
			look[i]--;
		}
		else{
			look[i] = -look[i] - 1;
		}
		if(can[look[i]]){
			if(sz > 1){
				printf("Not defined\n");
			}
			else{
				if(need){
					printf("Truth\n");
				}
				else{
					printf("Lie\n");
				}
			}
		}
		else{
			if(need){
				printf("Lie\n");
			}
			else{
				printf("Truth\n");
			}
		}
	}
	return 0;
}