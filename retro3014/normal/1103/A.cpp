#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;
typedef long long ll;
#define MAX_N 100

string str;

int c1, c2;

int main(){
	cin>>str;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='0'){
			if(c1==1){
				printf("1 1\n");
				c1 = 0;
			}else{
				printf("3 1\n");
				c1 = 1;
			}
		}else{
			if(c2==1){
				printf("1 1\n");
				c2 = 0;
			}else{
				printf("1 3\n");
				c2 = 1;
			}
		}
	}
	return 0;
}