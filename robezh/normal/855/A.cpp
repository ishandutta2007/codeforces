#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string names[105];
int n;

int main(){
	scanf("%d",&n);
	getchar();
	for(int i = 0; i < n; i++){
		getline(cin,names[i]);
		bool exist = false;
		for(int j = 0; j < i; j++){
			if(names[i] == names[j]){
				exist = true;
			}
		}
		if(exist) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}