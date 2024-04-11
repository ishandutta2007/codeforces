#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long LL;
#define vint vector<int>
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int a[300];
int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	string ans = "";
	int l = s.size();
	for(int i = 0;i < l;++i)
		a[s[i]]++;
	for(int i = 0;i < 300;++i)
		if(a[i] > 0)
		{
			if(a[i] % k != 0)
			{
				cout << -1;
				return 0;
			}
			for(int j = 0;j < a[i] / k;++j) 
				ans += char(i);
		}
	for(int i = 0;i < k;++i)
		cout << ans;
	cout << endl;
	return 0;
}