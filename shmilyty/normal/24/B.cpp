#include<bits/stdc++.h> 
using namespace std;
 
int ko[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
 
struct race {
	string name;
	vector<int> vict;
};
 
bool comp1 (race a, race b)
{
	int as = 0, bs = 0;
	for(int i = 0; i < 10; i++)
	{
		as += ko[i] * a.vict[i];
		bs += ko[i] * b.vict[i];
	}
	if(as != bs) return as > bs;
	
	int i = 0;
	while(i < 50 && a.vict[i] == b.vict[i]) i++;
	return a.vict[i] > b.vict[i];
}
 
bool comp2 (race a, race b)
{
	if(a.vict[0] != b.vict[0]) return a.vict[0] > b.vict[0];
 
	int as = 0, bs = 0;
	for(int i = 0; i < 10; i++)
	{
		as += ko[i] * a.vict[i];
		bs += ko[i] * b.vict[i];
	}
	if(as != bs) return as > bs;
 
	int i = 1;
	while(i < 50 && a.vict[i] == b.vict[i]) i++;
	return a.vict[i] > b.vict[i];
}
 
int main ()
{
	map <string, vector<int> > racer;
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n; cin >> n;
		for(int i = 0; i < n; i++)
		{
			string r; cin >> r;
			if(racer[r].size() == 0) racer[r].resize(50, 0);
			racer[r][i]++;
		}
	}
 
	vector<race> sorted(racer.size());
	int i = 0;
	for(map<string, vector<int> >::iterator it = racer.begin(); it != racer.end(); it++)
	{
		sorted[i].name = (*it).first;
		sorted[i].vict = (*it).second;
		i++;
	}

	sort(sorted.begin(), sorted.end(), comp1);
	cout << sorted[0].name << endl;
	sort(sorted.begin(), sorted.end(), comp2);
	cout << sorted[0].name << endl;
}