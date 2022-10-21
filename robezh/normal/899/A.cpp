#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int n;
int a1, a2;
int res = 0;

int main(){
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp == 1) a1 ++;
		else a2 ++;
	}
	if(a2 > a1) return !printf("%d", a1);
	else return !printf("%d", a2 + (a1-a2)/3);
}