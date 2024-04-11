#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n;
string a;

int main(){
	scanf("%d", &n);
	getchar();
	getline(cin,a);
	int x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 'L') x--;
		else if(a[i] == 'R') x++;
		else if(a[i] == 'U') y++;
		else if(a[i] == 'D') y--;
	}
	cout << n - abs(x) - abs(y);
}