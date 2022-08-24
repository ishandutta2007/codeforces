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
	int N;
	int num[1100];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	sort (num, num + N);
	
	int count = 1, cur = 1, hi = 1;
	for (int i = 1; i < N; i++)
	{
		if (num[i] != num[i-1])
		{
			cur = 1;
			count++;
		}
		else
		{
			cur++;
			hi = max (cur, hi);
		}
	}
	
	cout << hi << " " << count << "\n";
}