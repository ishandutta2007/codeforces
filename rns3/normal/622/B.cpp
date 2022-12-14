#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("2.in", "r", stdin);
	int x, y, z;
	scanf("%d:%d", &x, &y);scanf("%d", &z);
	int a = x * 60 + y + z;
	a %= 1440;
	printf("%02d:%02d\n", a / 60, a % 60);
}