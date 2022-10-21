#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	string a;
	int cnt = 0;
	string str[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	getline(cin,a);
	int alen = a.length();
	for(int i = 0; i < 5; i++){
		
		int len = str[i].length();
		for(int j = 0; j < alen - len + 1; j++){
			//printf("%d",j);
			int len = str[i].length();
			//printf("strlen[%d] = %d\n", i, len);
			if(a.substr(j, len) == str[i]){
				cnt++;
			}
		}
	}
	if(cnt == 1) printf("YES");
	else printf("NO");
}