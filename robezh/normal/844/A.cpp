#include<cstdio>
#include<iostream>
using namespace std;

char str[1005];
int numOfLetter[28];
int n;
int len; 

int main(){
	for(int i = 0; i < 1005; i++){
		str[i] = '\0';
	}
	for(int i = 0; i < 26; i++){
		numOfLetter[i] = 0;
	}
	scanf("%s", str);
	scanf("%d", &n);
	int len = 0;
	int count = 0;
	while(str[len] != '\0'){
		len++;
	}
	for(int i = 0; i< len; i++){
		if(numOfLetter[str[i]-'a'] == 0){
			count ++;
			numOfLetter[str[i]-'a']++;
		}
		else numOfLetter[str[i]-'a']++;
	}
	if(len < n ){
		printf("impossible\n");
	}
	else if(n - count > 0){
		printf("%d\n", n-count);
	}
	else{
		//printf("special\n");
		printf("0\n");
	}
	
}