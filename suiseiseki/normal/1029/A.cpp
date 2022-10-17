#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n, m;
	string s;
	cin >> n >> m >> s;
	int temp;
	for(int i = 0; i < n; i++) if(s.substr(0, i) == s.substr(n-i, i)) temp = i;
	for(int i = 1; i < m; i++) cout << s.substr(0, n - temp);
	cout << s << endl;
	return 0;
}