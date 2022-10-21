#include<cstdio>
using namespace std;

int main(){
	int n,k,t;
	int res;
	scanf("%d %d %d", &n, &k, &t);
	if(t <= 0 || t >= n + k) res = 0;
	else if(t <= k) res = t;
	else if(t >= n) res = n + k - t;
	else res = k;
	
	printf("%d", res);
}