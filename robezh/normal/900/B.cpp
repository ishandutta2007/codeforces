#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int a,b,c;

int main(){
	cin >> a >> b >> c;
	for(int t = 1; t < 100000; t++){
		a *= 10;
		int tmp = a/b;
		if(tmp == c) return !printf("%d", t);
		a -= tmp*b;
	}
	printf("-1");
	return 0;
}