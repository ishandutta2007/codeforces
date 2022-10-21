#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

vector<int> que;

int main(){
	int n;
	long long k;
	cin>>n>>k;
	int power[505];
	int maxpow = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&power[i]);
		maxpow = max(maxpow, power[i]);
		que.push_back(power[i]);
	}
	if(k >= n){
		printf("%d",maxpow);
		return 0;
	}
	int wincount = 0;
	int times = 0;
	while(wincount < k && times <= n){
		if(que[0] > que[1]){
			int be2 = que[1];
			que.erase(que.begin()+1);
			que.push_back(be2);
			wincount++;
			//printf("1");
		}
		else{
			int be = que[0];
			que.erase(que.begin());
			que.push_back(be);
			wincount = 1;
			//printf("1");
		}
		times++;
	}
	printf("%d", que[0]);
	
	
	
}