#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<int, int> M;
string str;
int n;

int main(){
	int x = 0, y = 0;
	M[0] = -1;
	int ans = 0;
	scanf("%d", &n);
	getchar();
	getline(cin,str);
	for(int i = 0; i < n; i++){
		if(str[i] == '1'){
			x ++;
		}
		else{
			y ++;
		}
		if(!M.count(x-y)){
			M[x-y] = i;
		}
		else{
			ans = max(ans, i - M[x-y]);
		}
	}
	printf("%d", ans);
	
	return 0;
}