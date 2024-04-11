#include<cstdio>
#include<iostream>
using namespace std;

bool a[3][10];
int n;

bool checkone(int num){
	bool ans = false;
	for(int i = 0; i < n; i++) ans |= a[i][num];
	
	return ans;
}

bool checktwo(int num){
	int f = num / 10; int s = num % 10;
	//cout << (a[0][f] & a[1][s]) << (a[1][f] & a[0][s]) << (a[0][f] & a[2][s]) << (a[2][f] & a[0][s])<<  (a[2][f] & a[1][s]) << (a[1][f] & a[2][s]);
	bool ans = false;
	if(n == 1) return false;
	if(n == 2) return (a[0][f] && a[1][s]) || (a[1][f] && a[0][s]);
	else return (a[0][f] && a[1][s]) || (a[1][f] && a[0][s]) || (a[0][f] && a[2][s]) || (a[2][f] && a[0][s]) || (a[2][f] && a[1][s]) || (a[1][f] && a[2][s]);
}

bool checkthree(int num){
	int f = num / 100; int s = (num / 10) % 10; int t = num % 10;
	return (a[0][f] && a[1][s] && a[2][t]) || (a[1][f] && a[0][s] && a[2][t]) || 
		(a[0][f] && a[2][s] && a[1][t]) || (a[2][f] && a[0][s] && a[1][t]) || 
		(a[2][f] && a[1][s] && a[0][t]) || (a[1][f] && a[2][s] && a[0][t]);
}

int main(){
	
	scanf("%d", &n);
	int tmp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 10; j++){
			a[i][j] = false;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			scanf("%d", &tmp);
			a[i][tmp] = true;
		}
	}
//	for(int i = 0; i < 3; i++){
//		for(int j = 0; j < 10; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	//printf("%d", checktwo(88));
	int maxnum = 1;
	while(maxnum < 10){
		if(checkone(maxnum)) maxnum++;
		else{
			printf("%d", maxnum-1);
			return 0;
		}
	}
	if(n == 1) return 0 && printf("9");
	while(maxnum < 100){
		if(checktwo(maxnum)) maxnum++;
		else{
			printf("%d", maxnum-1);
			return 0;
		}
	}
	if(n == 2) return 0 && printf("99");
	while(maxnum < 1000){
		if(checkthree(maxnum)) maxnum ++;
		else{
			printf("%d", maxnum-1);
			return 0;
		}
	}
	printf("66666");
	
}