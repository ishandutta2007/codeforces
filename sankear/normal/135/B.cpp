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

struct tp{
	int x, y;
};

bool fl1, fl2;
tp v1, v2;
bool used[20], use[20];
int perm[20];
tp p[20], p1[20], p2[20];

inline bool check(const tp &a, const tp &b, const tp &c){
	v1.x = a.x - b.x;
	v1.y = a.y - b.y;
	v2.x = c.x - b.x;
	v2.y = c.y - b.y;
	return v1.x * v2.x + v1.y * v2.y == 0;
}

inline int sqr(int a){
	return a * a;
}

inline int dist(const tp &a, const tp &b){
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

void gen2(int x){
	if(x >= 4){
		if(!check(p1[perm[0]], p1[perm[1]], p1[perm[2]])){
			return;
		}
		if(!check(p1[perm[1]], p1[perm[2]], p1[perm[3]])){
			return;
		}
		if(!check(p1[perm[2]], p1[perm[3]], p1[perm[0]])){
			return;
		}
		if(!check(p1[perm[3]], p1[perm[0]], p1[perm[1]])){
			return;
		}
		int d = dist(p1[perm[0]], p1[perm[1]]);
		if(dist(p1[perm[1]], p1[perm[2]]) != d){
			return;
		}
		if(dist(p1[perm[2]], p1[perm[3]]) != d){
			return;
		}
		if(dist(p1[perm[3]], p1[perm[0]]) != d){
			return;
		}
		fl1 = true;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(!use[i]){
			perm[x] = i;
			use[i] = true;
			gen2(x + 1);
			use[i] = false;
		}
	}
}

void gen3(int x){
	if(x >= 4){
		if(!check(p2[perm[0]], p2[perm[1]], p2[perm[2]])){
			return;
		}
		if(!check(p2[perm[1]], p2[perm[2]], p2[perm[3]])){
			return;
		}
		if(!check(p2[perm[2]], p2[perm[3]], p2[perm[0]])){
			return;
		}
		if(!check(p2[perm[3]], p2[perm[0]], p2[perm[1]])){
			return;
		}
		if(dist(p2[perm[0]], p2[perm[1]]) != dist(p2[perm[2]], p2[perm[3]])){
			return;
		}
		if(dist(p2[perm[1]], p2[perm[2]]) != dist(p2[perm[0]], p2[perm[3]])){
			return;
		}
		fl2 = true;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(!use[i]){
			perm[x] = i;
			use[i] = true;
			gen3(x + 1);
			use[i] = false;
		}
	}
}

void gen1(int x, int y){
	if(x >= 8){
		if(y != 4){
			return;
		}
		int k1 = 0, k2 = 0;
		for(int i = 0; i < 8; i++){
			if(used[i]){
				p1[k1++] = p[i];
			}
			else{
				p2[k2++] = p[i];
			}
		}
		fl1 = fl2 = false;
		gen2(0);
		gen3(0);
		if(fl1 && fl2){
			printf("YES\n");
			bool first = true;
			for(int i = 0; i < 8; i++){
				if(used[i]){
					if(!first){
						printf(" ");
					}
					first = false;
					printf("%d", i + 1);
				}
			}
			printf("\n");
			first = true;
			for(int i = 0; i < 8; i++){
				if(!used[i]){
					if(!first){
						printf(" ");
					}
					first = false;
					printf("%d", i + 1);
				}
			}
			printf("\n");
			exit(0);
		}
		return;
	}
	gen1(x + 1, y);
	used[x] = true;
	gen1(x + 1, y + 1);
	used[x] = false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for(int i = 0; i < 8; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	gen1(0, 0);
	printf("NO\n");
	return 0;
}