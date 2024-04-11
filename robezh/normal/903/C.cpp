#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int n;
int num[5005];
map<int, int> M;


int main(){
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> num[i];
		if(!M.count(num[i])){
			M[num[i]] = 1;
			ans = max(ans, 1);
		}
		else{
			M[num[i]] ++;
			ans = max(ans, M[num[i]]);
		}
	}
	cout << ans;
}