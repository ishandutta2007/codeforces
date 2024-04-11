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
	int arr[110];
	int hloc = 0, lloc = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > arr[hloc])
			hloc = i;
		if (arr[i] <= arr[lloc])
			lloc = i;
	}
	
	if (hloc > lloc)
	{
		cout << hloc + N - 1 - lloc - 1 << "\n";
	}
	else cout << hloc + N - 1 - lloc << "\n";
}