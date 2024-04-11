#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string c[123],h;
int n;
vector<int> sx;
bool qgl[123];
int main()
{
	cin>>n>>h;
	for(int i=0;i<n;i++)cin>>c[i];
	int cnt=0,start=0;
	if(n%2==0)return puts("home"),0;
	else return puts("contest"),0;
}