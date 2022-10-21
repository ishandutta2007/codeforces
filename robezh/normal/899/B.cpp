#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int mon[60] = {31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,
31,29,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31,
31,28,31,30,31,30,31,31,30,31,30,31};

int n;
int a[24];

bool check_single(int k){
	for(int i = 0; i < n; i++){
		if(a[i] != mon[(k+i)%60]) return false;
	}
	return true;
}

bool check(){
	for(int i = 0; i < 60; i++){
		if(check_single(i)) return true;
	}
	return false;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	printf(check() ? "YES" : "NO");
}