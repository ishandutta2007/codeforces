#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
char s[maxn]; 
int fl[26];
char t[maxn];
int n;
bool check()
{
	int fl = 0;
	for(int i = 1; i <= n; i++)
		if(t[i] != t[n + 1 - i]) return 0;
		else if(t[i] != s[i]) fl = 1;
	return fl;
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++)	
		if((n & 1) && i == (n + 1) / 2) continue;
		else fl[s[i] - 'a'] = 1;
	int cnt = 0;
	for(int i = 0; i < 26; i++)
		cnt += fl[i];
	if(cnt < 2)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int ncnt = 0;
		for(int j = i + 1; j <= n; j++)
			t[++ncnt] = s[j];
		for(int j = 1; j <= i; j++)
			t[++ncnt] = s[j];
		if(check())
		{
			cout<<"1"<<endl;
			return 0;
		}
	}
	cout<<2<<endl;
	return 0;
 }