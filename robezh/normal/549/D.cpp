#include<cstdio>
#include<iostream>
using namespace std;

int a,b;
char c[105][105];

int check(int i, int j){
	if(i == a-1 && j == b-1) return true;
	if(i == a-1) return c[i][j] != c[i][j+1];
	if(j == b-1) return c[i][j] != c[i+1][j];
	return c[i+1][j] + c[i][j+1] - c[i+1][j+1] != c[i][j];
}

int main() {
    scanf("%d%d", &a, &b);
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            cin >> c[i][j];
    int cnt = 0;
    for(int i = 0; i < a; i++){
    	for(int j = 0; j < b; j++){
    		if(check(i,j)) cnt++;
		}
	}
	cout << cnt;
}