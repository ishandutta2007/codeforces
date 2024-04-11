#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 505
#define ll long long
using namespace std;
int ask(int l, int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	fflush(stdout);
	int t;
	cin>>t;
	//if(t == -1) while(1);
	return t;
}
int n, t;
int ans[maxn];
int gfr(int i)
{
	int tr = i;
	if(n % 2) tr = i - 1;
	int fl = 0, ns = 0;
	int ls = t;
	int ans = 0;
	while(1)
	{
		int nr = ask(tr, i);
		if((nr + ls) % 2 == i % 2) //
		{ // front
		 	if(!fl && !ns)
		 	{
		 		fl = 1;
		 		ans = (i + t - nr) / 2;
			}	
			ns ^= 1;
		} 
		else ns ^= 2;
		ls = nr;
		if(!ns && fl) break;
	}
	return ans;
}
int ged()
{
	int fl = 0, ns = 0;
	int ls = t;
	int ans = 0;
	while(1)
	{
		int nr = ask(2, 3);
		if(!((nr + ls) % 2)) // 
		{ // front
		 	if(!fl && !ns)
		 	{
		 		fl = 1;
		 		ans = ((n - 1) + t - nr) / 2;
			}	
			ns ^= 1;
		} 
		else ns ^= 2;
		ls = nr;
		if(!ns && fl) break;
	}
	return ans;
}
int main()
{
	cin>>n>>t;
	if(n == 1)
	{
		cout<<"! "<<t<<endl;
		fflush(stdout);
		return 0;
	}
	ans[n] = t;
	for(int i = 2; i <= n; i++)
		ans[i] = gfr(i);
	if(!(n % 2)) ans[1] = gfr(1);
	else
		ans[1] = t - ged();
	cout<<"! ";
	for(int i = 1; i <= n; i++)
		cout<<ans[i] - ans[i - 1];
	cout<<endl;
	fflush(stdout);
	return 0;
}