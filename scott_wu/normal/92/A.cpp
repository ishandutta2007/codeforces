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
	int N, M;
	cin >> N >> M;
	
	int cur = 0;
	while (true)
	{
		if (M < cur + 1)
			break;
		M -= cur + 1;
		
		cur = (cur + 1) % N;
	}
	
	cout << M << "\n";
	return 0;
}