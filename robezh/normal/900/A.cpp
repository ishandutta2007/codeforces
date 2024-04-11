#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
int cntn = 0, cntp = 0;

int main(){
	int a,b;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a < 0) cntn ++;
		else cntp ++;
	}
	if(cntn <= 1 || cntp <= 1) return !printf("Yes");
	else !printf("No");
}