#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str;
int Q[105];

int main(){
	int sum = 0;
	getline(cin, str);
	if(str[0] == 'Q') Q[0] = 1;
	else Q[0] = 0;
	for(int i = 1; i < str.length(); i++){
		if(str[i] == 'Q') Q[i] = Q[i-1] + 1;
		else Q[i] = Q[i-1];
	}
	for(int i = 1; i < str.length() - 1; i++){
		if(str[i] == 'A') sum += Q[i-1] * (Q[str.length()-1] - Q[i]);
	}
	cout << sum;
}