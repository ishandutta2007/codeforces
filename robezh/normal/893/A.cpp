#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int n;
bool good[5];

bool check(int k){
	return !good[k];
}

void change(int k){
	for(int j = 1; j <= 3; j++){
		if(j != k) good[j] = good[j] ? false : true;
	}
}

int main(){
	good[1] = true , good[2] = true, good[3] = false;
	//for(int j = 1; j <= 3; j ++) cout << good[j];
	//cout << endl;
	scanf("%d", &n);
	int tmp;
	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		if(check(tmp)) return !printf("No");
		change(tmp);
		//for(int j = 1; j <= 3; j ++) cout << good[j];
		//cout << endl;
	}
	return !printf("Yes");
}