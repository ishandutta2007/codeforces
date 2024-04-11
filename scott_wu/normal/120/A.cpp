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
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	string str;
	int x;
	fin >> str >> x;
	
	bool t = true;
	if (str[0] == 'b')
		t = !t;
	if (x == 2)
		t = !t;
	
	if (t) fout << "L\n";
	else fout << "R\n";
	return 0;
}