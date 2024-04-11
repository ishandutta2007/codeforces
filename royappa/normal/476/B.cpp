#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>


//http://codeforces.com/contest/476/problem/B



using namespace std;


typedef long long LL;



int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();

	int p = 0;
	for (int i = 0; i < n; i++)
	{
		p += (s1[i] == '+' ? 1 : -1);
	}
	vector<int> poss;
	poss.push_back(0);
	for (int i = 0; i < n; i++)
	{
		vector<int> poss2;
		for (int j = 0; j < poss.size(); j++)
		{
			int p2 = poss[j];
			if (s2[i] == '?')
			{
				poss2.push_back(p2+1);
				poss2.push_back(p2-1);
			}
			else
			{
				poss2.push_back(s2[i] == '+' ? p2+1 : p2-1);
			}
		}
		poss = poss2;
	}
	//for (int i = 0; i < poss.size(); i++)
	//	cout << poss[i] << " "; cout << endl;
	int num = count(poss.begin(), poss.end(), p);
	//cout << p << " " << num << endl;
	printf("%.12lf\n",(double) num/(double)poss.size());
	exit(0);
}