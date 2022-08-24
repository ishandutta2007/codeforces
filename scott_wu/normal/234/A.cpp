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
	int N; fin >> N;
	char ch[110];
	for (int i = 0; i < N; i++)
		fin >> ch[i];
	
	int mpair[110][2];
	for (int i = 0; i < N / 2; i++)
	{
		mpair[i][0] = i;
		mpair[i][1] = i + N / 2;
		if (ch[i] == 'R' && ch[i+N/2] == 'L')
			swap (mpair[i][0], mpair[i][1]);
	}
	
	for (int i = 0; i < N / 2; i++)
	{
		fout << mpair[i][0] + 1 << " " << mpair[i][1] + 1 << "\n";
	}
	return 0;
}