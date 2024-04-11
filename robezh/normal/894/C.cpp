#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int num[1005];
vector<int> V;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]);
	for(int i = 1; i < n; i++){
		if(num[i] % num[0] != 0) return !printf("-1");
	}
	for(int i = 0; i < n; i++){
		V.push_back(num[i]);
		V.push_back(num[0]);
	}
	printf("%d\n",V.size());
	for(int i = 0; i < V.size(); i++) printf("%d ", V[i]);
}