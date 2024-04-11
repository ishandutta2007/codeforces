#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
	int n;
	string str;
	scanf("%d",&n);
	getchar();
	getline(cin,str);
	int s2f = 0;
	int f2s = 0;
	for(int i = 0; i < n - 1; i++){
		if(str[i] == 'S' && str[i+1] == 'F') s2f ++;
		else if(str[i] == 'F' && str[i+1] == 'S') f2s ++;
	}
	if(s2f > f2s) printf("YES");
	else printf("NO");
}