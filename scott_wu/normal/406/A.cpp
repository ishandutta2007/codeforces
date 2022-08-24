#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN = 1100;
const int MAXQ = 1000100;

int N, Q;
int board[MAXN];
string str;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	getline (cin, str);
	for (int i = 0; i < N; i++)
	{
		getline (cin, str);
		board[i] = (int) (str[2*i] - '0');
	}
	
	int ctot = 0;
	for (int i = 0; i < N; i++)
		ctot = (ctot + board[i]) % 2;
	
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int t; cin >> t;
		if (t <= 2)
		{
			ctot = 1 - ctot;
			cin >> t;
		}
		else
		{
			printf ("%c", ((char) (ctot + '0')));
		}
	}
	printf ("\n");
	
	return 0;
}