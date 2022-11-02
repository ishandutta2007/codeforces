#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map < string, int > A, B;
pair < string, int > moves[1100];
string winner; 
int score;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		cin >> moves[i].first >> moves[i].second;
	for (int i = 0; i < n; i ++)
		A[moves[i].first] += moves[i].second;

	score = -1000000000;
	for (map < string, int > :: iterator it = A.begin(); it != A.end(); it ++)
		score = max(score, it->second);

	for (int i = 0; i < n; i ++)
	{
		B[moves[i].first] += moves[i].second;
		if (B[moves[i].first] >= score && A[moves[i].first] == score)
		{
			cout << moves[i].first << endl;
			return 0;
		}
	}

	return 0;
}