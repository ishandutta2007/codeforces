#include<cstdio>
#include<iostream>
#include<set>
#include<string>
using namespace std;

string str;
int n;

int main(){
	set<char> S;
	int res = 0;
	scanf("%d", &n);
	getchar();
	getline(cin,str);
	for(int i = 0; i < n; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			S.insert(str[i]);
			int size = S.size();
			res = max(res, size);
		}
		else{
			S.clear();
		}
	}
	printf("%d",res);
	
}