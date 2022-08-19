#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
ll sx, sy; 
int main()
{
	int n, m;
	cin>>n>>m;
	int x1 = (n / 9) + 2;
	for(int j = 0; j < x1; j++)
		cout<<"9";
	cout<<endl;
	for(int j = 0; j < x1; j++)
		cout<<"9";
	for(int j = 0; j < x1; j++)
		if(j == x1 - 1) cout<<"1";
		else cout<<"0"; 
	return 0;
 }