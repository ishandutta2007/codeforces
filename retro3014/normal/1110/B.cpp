#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K;
int ans = 0;
vector<int> v;
vector<int> v2;

typedef long long ll;

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x); v.push_back(x);
		if(i!=0)	v2.push_back(v.back()-v[v.size()-2]-1);
	}
	sort(v2.begin(), v2.end());
	ans = v.back()-v.front()+1;
	for(int i=1; i<K; i++){
		ans-=v2.back();	v2.pop_back();
	}
	printf("%d", ans);
	return 0;
}