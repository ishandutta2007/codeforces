#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    vector<int> res;
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i+=2){
    	res.push_back(i);
	}
	for(int i = 1; i <= n; i+=2){
		res.push_back(i);
	}
	for(int i = 2; i <= n; i+=2){
    	res.push_back(i);
	}
    printf("%d\n",res.size());
    for(int i = 0 ; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
}