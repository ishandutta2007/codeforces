#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string a;
	getline(cin, a);
	int cnt = 0;
	bool oneAppear = false;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == '1') oneAppear = true;
		if(a[i] == '0' && oneAppear) cnt ++;
	}
	if(cnt >= 6) printf("yes");
	else printf("no");
}