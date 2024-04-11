#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string str;
char c1, c2;
int n;
string tmp;

int main(){
	int a = 0, b = 0;
	getline(cin,str);
	c1 = str[0]; c2 = str[1];
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin,tmp);
		if(str == tmp){
			a = 1; b = 1; break;
		}
		if(c1 == tmp[1]){
			a = 1;
		}
		if(c2 == tmp[0]){
			b = 1;
		}
	}
	if(a&&b) printf("YES");
	else printf("NO");
	
	return 0;
}