#include<bits/stdc++.h>
using namespace std;

#define N 1000010

bool vis[N];
int n, arr[N], d;

int main(){
	scanf("%d %d", &n, &d);

	for(int i = 1; i <= n; i ++) scanf("%d", arr + i);

	vis[0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = N - arr[i]; j >= 0; j --) if(vis[j]) vis[j + arr[i]] = true;
	}

	int cur = 0, day = 0, pos = 0;

	while(cur < N){
		for(pos = cur + d; pos > cur; pos --){
			if(vis[pos]) break;
		}

		if(pos == cur) break;
		else{
			cur = pos; day ++;
		}
	}
	cout << cur << " " << day << endl;
}