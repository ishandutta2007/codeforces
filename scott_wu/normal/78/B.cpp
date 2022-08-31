#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	string str = "ROYG";
	for (int i = 0; i < N - 3; i++)
		cout << str[i%4];
	cout << "BIV\n";
}