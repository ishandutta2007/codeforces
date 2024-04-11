#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string S; int n;
int main() {
	for (int i = 1; i <= 10000; i++)S += to_string(i);
	cin >> n; n--;
	cout << S[n] << endl;
	return 0;
}