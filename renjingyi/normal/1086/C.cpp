#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
int trans[30];
bool used[30];
int tmp[30];
bool asd[30];
string s, a, b;
int k;
void fill(const bool &x)
{
	if(x == 0)
		for(int i = 0; i < k; i ++)
		{
			tmp[i] = trans[i];
			asd[i] = used[i];
		}
	int pos1 = 0, pos2 = 0;
	for(; pos1 < k; pos1 ++)
		if(tmp[pos1] == -1)
		{
			for(; asd[pos2]; pos2 ++);
			tmp[pos1] = pos2;
			pos2 ++;
		}
}
bool check1(const int &pos)
{
	for(int i = 0; i < k; i ++)
	{
		tmp[i] = trans[i];
		asd[i] = used[i];
	}
	bool ok = 1;
	for(int i = pos; i < s.size(); i ++)
	{
		int x = s[i] - 'a';
		if(tmp[x] > -1)
		{
			if(tmp[x] == a[i] - 'a')
				continue;
			else if(tmp[x] < a[i] - 'a')
			{
				ok = 0;
				break;
			}
			else
			{
				fill(1);
				break;
			}
		}
		bool get = 0;
		for(int j = a[i] - 'a' + 1; j < k; j ++)
			if(!asd[j])
			{
				tmp[x] = j;
				asd[j] = 1;
				fill(1);
				get = 1;
				break;
			}
		if(get)
		{
			ok = 1;
			break;
		}
		if(asd[a[i] - 'a'])
		{
			ok = 0;
			break;
		}
		tmp[x] = a[i] - 'a';
		asd[a[i] - 'a'] = 1;
	}
	return ok;
}
bool check2(const int &pos)
{
	for(int i = 0; i < k; i ++)
	{
		tmp[i] = trans[i];
		asd[i] = used[i];
	}
	bool ok = 1;
	for(int i = pos; i < s.size(); i ++)
	{
		int x = s[i] - 'a';
		if(tmp[x] > -1)
		{
			if(tmp[x] == b[i] - 'a')
				continue;
			else if(tmp[x] > b[i] - 'a')
			{
				ok = 0;
				break;
			}
			else
			{
				fill(1);
				break;
			}
		}
		bool get = 0;
		for(int j = b[i] - 'a' - 1; j >= 0; j --)
			if(!asd[j])
			{
				tmp[x] = j;
				asd[j] = 1;
				fill(1);
				get = 1;
				break;
			}
		if(get)
		{
			ok = 1;
			break;
		}
		if(asd[b[i] - 'a'])
		{
			ok = 0;
			break;
		}
		tmp[x] = b[i] - 'a';
		asd[b[i] - 'a'] = 1;
	}
	return ok;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		cin >> k;
		for(int i = 0; i < k; i ++)
		{
			trans[i] = tmp[i] = -1;
			used[i] = asd[i] = 0;
		}
		cin >> s >> a >> b;
		bool ok = 1;
		for(int i = 0; i < s.size(); i ++)
		{
			int x = s[i] - 'a';
			//cout << "now : " << i << " " << x << endl;
			if(a[i] == b[i])
			{
				//cout << "here1" << endl;
				if(trans[x] > -1)
				{
					if(trans[x] == a[i] - 'a')
						continue;
					ok = 0;
					break;
				}
				if(used[a[i] - 'a'])
				{
					ok = 0;
					break;
				}
				trans[x] = a[i] - 'a';
				used[a[i] - 'a'] = 1;
				tmp[x] = a[i] - 'a';
				asd[a[i] - 'a'] = 1;
				//cout << "give : " << a[i] - 'a' << " " << x << endl;
				continue;
			}
			if(trans[x] > -1)
			{
				//cout << "here2" << endl;
				if(trans[x] < a[i] - 'a' || trans[x] > b[i] - 'a')
				{
					ok = 0;
					break;
				}
				if(trans[x] > a[i] - 'a' && trans[x] < b[i] - 'a')
				{
					fill(0);
					break;
				}
				if(trans[x] == a[i] - 'a')
				{
					if(check1(i + 1))
					{
						fill(1);
						break;
					}
					else
					{
						ok = 0;
						break;
					}
				}
				else if(trans[x] == b[i] - 'a')
				{
					if(check2(i + 1))
					{
						fill(1);
						break;
					}
					else
					{
						ok = 0;
						break;
					}
				}
			}
			//cout << "here3" << endl;
			bool get = 0;
			for(int j = a[i] - 'a' + 1; j <= b[i] - 'a' - 1; j ++)
				if(!used[j])
				{
					trans[x] = j;
					used[j] = 1;
					fill(0);
					get = 1;
					break;
				}
			if(get)
			{
				ok = 1;
				break;
			}
			if(!used[a[i] - 'a'])
			{
				trans[x] = a[i] - 'a';
				used[a[i] - 'a'] = 1;
				if(check1(i + 1))
				{
					fill(1);
					break;
				}
				else
				{
					trans[x] = 0;
					used[a[i] - 'a'] = 0;
				}
			}
			if(!used[b[i] - 'a'])
			{
				trans[x] = b[i] - 'a';
				used[b[i] - 'a'] = 1;
				if(check2(i + 1))
				{
					fill(1);
					break;
				}
				else
				{
					trans[x] = 0;
					used[b[i] - 'a'] = 0;
				}
			}
			ok = 0;
			break;
		}
		if(ok)
		{
			//for(int i = 0; i < k; i ++)
			//	cout << "aaaaaaaaaaaaaaaaaaaaaaaaa : " << tmp[i] << " " << asd[i] << endl;
			fill(1);
			printf("YES\n");
			for(int i = 0; i < k; i ++)
				printf("%c", (char)(tmp[i] + 'a'));
			printf("\n");
		}
		else
			printf("NO\n");
	}
	
	return 0;
}
/*
4
5
abbacd
deedba
deedba
5
abbacd
deecba
deecba

4
bbcb
aada
aada
3
abc
bbb
bbb

*/