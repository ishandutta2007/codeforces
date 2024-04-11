#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

map<string, int> M;

int main(){
	int n;
	scanf("%d", &n);
	string str;
	getchar();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		getline(cin, str);
		while((int)str.find("kh") >= 0){
			int i = str.find("kh");
			str = str.substr(0, i) + "h" + (i + 2 < str.length() ? str.substr(i + 2, str.length() - i - 2) : "");
			//cout << str << endl;
		}
		while((int)str.find("u") >= 0){
			int i = str.find("u");
			str = str.substr(0, i) + "oo" + (i + 1 < str.length() ? str.substr(i + 1, str.length() - i - 1) : "");
		}
		if(!M.count(str)){
			cnt++;
			//cout << "new string: " << str <<endl;
		}
		M[str] = 1;
	}
	printf("%d\n", cnt);
}