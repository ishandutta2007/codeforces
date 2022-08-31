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
	
	int t; fin >> t;
	for (int i = 0; i < t; i++)
	{
		int x; fin >> x;
		fout << 1 - (x % 2) << "\n";
	}
}