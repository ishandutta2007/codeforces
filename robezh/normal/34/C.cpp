#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int exi[1005];
string str;
int num;
char c;

void printP(int a, int b){
	if(a == b) printf("%d", a);
	else printf("%d-%d", a,b);
}


int main(){
	fill(exi, exi+1005, false);
	getline(cin, str);
	int num = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] != ','){
			num *= 10;
			num += str[i] - '0';
		}
		if(str[i] == ',' || i == str.length() - 1){
			exi[num] = 1;
			num = 0;
		}
	}
	int fst, lst = -1;
	for(int i = 1; i < 1005; i++){
		if(exi[i]){
			if(lst == -1){
				lst = fst = i;
				continue;
			}
			
			if(i == lst+1){
				lst++;
			}
			else printP(fst, lst), printf(","), fst = i, lst = i;
		}
	}
	printP(fst, lst);
}