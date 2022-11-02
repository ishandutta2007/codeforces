#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
using Pir = pair<int, int>;
priority_queue<Pir> q0, q1;
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x, y; scanf("%d%d", &x, &y);
		if(x < y) q0.push(Pir(y, i));
		else q1.push(Pir(-y, i));
	}
	if(q0.size() > q1.size()){
		printf("%d\n", q0.size());
		while(!q0.empty()){
			printf("%d ", q0.top().second);
			q0.pop();
		}
	}
	else{
		printf("%d\n", q1.size());
		while(!q1.empty()){
			printf("%d ", q1.top().second);
			q1.pop();
		}
	}
	printf("\n");
	return 0;
}