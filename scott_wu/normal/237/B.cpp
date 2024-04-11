#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 55;

int N, S;
int c[MAXN];
int arr[MAXN][MAXN];
int goal[MAXN][MAXN];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> c[i];
	
	S = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < c[i]; j++)
		{
			cin >> arr[i][j];
			S++;
			goal[i][j] = S;
		}
	
	int res = 0;
	vector <pair <pair <int, int>, pair <int, int> > > vres;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < c[i]; j++)
			if (arr[i][j] != goal[i][j])
			{
				res++;
				int resk, resl;
				for (int k = 0; k < N; k++)
					for (int l = 0; l < c[k]; l++)
						if (arr[k][l] == goal[i][j])
						{
							resk = k;
							resl = l;
							vres.push_back (make_pair (make_pair (i+1, j+1), make_pair (k+1, l+1)));
						}
				
				swap (arr[i][j], arr[resk][resl]);
			}
	
	cout << res << "\n";
	for (int i = 0; i < vres.size(); i++)
		cout << vres[i].first.first << " " << vres[i].first.second << " " << vres[i].second.first << " " << vres[i].second.second << "\n";
	return 0;
}