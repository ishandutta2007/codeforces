#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<int> v1, v2;
int ans = 1;
vector<int> vv1, vv2;

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		v1.push_back(x);
	}
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		v2.push_back(x);
	}
	for(int i=0; i<N-1; i++){
		vv1.push_back(v1[i+1]-v1[i]);
		vv2.push_back(v2[i+1]-v2[i]);
	}
	sort(vv1.begin(), vv1.end()); sort(vv2.begin(), vv2.end());
	for(int i=0; i<vv1.size(); i++){
		if(vv1[i]!=vv2[i])	ans = 0;
	}
	if(v1[0]!=v2[0])	ans = 0;
	if(v1[N-1]!=v2[N-1])	ans = 0;
	if(ans==1){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}