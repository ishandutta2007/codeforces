#include <bits/stdc++.h>
using namespace std;
#define N 105

string s;

int main(){
	int i, j, n;
	scanf("%d", &n);
	cin >> s;
	for(i = 0; i < n; ){
		if(i >= n - 2){
			printf("%c", s[i]);
			i++;
		}
		else if(s.substr(i, 3) == "ogo"){
			printf("***");
			i += 3;
			while(s.substr(i, 2) == "go") i += 2;
		}
		else{
			printf("%c", s[i]);
			i++;
		}
	}
}