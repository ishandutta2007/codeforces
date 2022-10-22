#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int lmin[100005];
int rmin[100005];
int num[100005];

int main(){
	int res;
	int n,k;
	int tmp;
	scanf("%d%d",&n,&k);
	if(k == 1){
		res = 1000000005;
		for(int i = 0; i < n; i++){
			scanf("%d",&tmp);
			res = min(res, tmp);
		}
	}
	else if(k >= 3){
		res = -1000000005;
		for(int i = 0; i < n; i++){
			scanf("%d",&tmp);
			res = max(res, tmp);
		}
	}
	else{
		for(int i = 0; i < n; i++){
			scanf("%d",&num[i]);
		}
		lmin[0] = num[0];
		for(int i = 1; i < n; i++){
			lmin[i] = min(lmin[i-1], num[i]);
		}
		rmin[n-1] = num[n-1];
		for(int i = n - 2; i >= 0; i--){
			rmin[i] = min(rmin[i+1], num[i]);
		}
		res = -1000000005;
		for(int i = 0; i < n-1; i++){
			res = max(res, max(lmin[i], rmin[i+1]));
		}
	}
	printf("%d",res);
}