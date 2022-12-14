#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX_N 1000

int N;
int sum[MAX_N+1];
int d[MAX_N+1];
int p[MAX_N+1];

int main(){
	scanf("%d", &N);
	for(int i=2; i<=N; i++){
		int x; scanf("%d", &x);
		p[i] = x;
		sum[x]++;
	}
	for(int i=2; i<=N; i++){
		if(sum[i]!=0)	continue;
		d[p[i]]++;
	}
	for(int i=1; i<=N; i++){
		if(sum[i]!=0 && d[i]<3){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}