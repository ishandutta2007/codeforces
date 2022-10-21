#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


int sm[4];
string str[3];

string rever(string a){
	return string(1,a[2]) + string(1,a[1]) + string(1,a[0]);
}

void print_s(int s){
	for(int i = 0; i < 3; i ++){
		if(sm[i] == s) printf("%c", i+'A');
	}
}

int main(){
	for(int i = 0; i < 3; i ++){
		getline(cin, str[i]);
		if(str[i][1] == '<') str[i] = rever(str[i]);
		//cout << str[i];
	}
	
	for(int i = 0; i < 3; i++){
		sm[str[i][2]-'A']++;
	}
	if(sm[0] == 1 && sm[1] == 1 && sm[2] == 1) return !printf("Impossible\n");
	for(int i = 2; i >= 0; i--){
		print_s(i);
		//cout << endl;
	}
	
}