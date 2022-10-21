#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int ans = 10000000;
	int pans = 0;
	int len = str.length();
	
	for(int i = 'a'; i <= 'z'; i++){
		pans = -1;
		int prev = -1;
		for(int j = 0; j < len; j++){
			if(str[j] == i){
				//printf("weq");
				pans = max(pans, j - prev);
				prev = j;
				//printf("pans = %d\n", pans);
			}
		}
		if(pans != -1) pans = max(pans, len - prev);
		if(pans != -1) ans = min(ans, pans);
	}
	cout << ans;
}