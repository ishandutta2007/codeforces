#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool single[105];
int p[105];
int n;

int getsinglestab(int x,int y){
	single[x] = true;
	single[y] = true;
	bool first = true;
	int tmpa, sum = 0;
	for(int i = 0; i < n; i++){
		if(single[i]) continue;
		if(first){
			tmpa = p[i];
			first = false;
		}
		else{
			sum += p[i] - tmpa;
			first = true;
		}
	}
	single[x] = false;
	single[y] = false;
	
	return sum;
}

int main(){
	memset(single, false, sizeof(single));
	scanf("%d", &n);
	n *= 2;
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
	sort(p,p+n);
//	for(int i = 0; i < n; i++) printf("%d ", p[i]);
//	printf("\n");
	int res = 1000000000;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			//printf("%d\n",getsinglestab(i,j));
			res = min(res, getsinglestab(i,j));
		}
	}
	printf("%d\n", res);
	
}