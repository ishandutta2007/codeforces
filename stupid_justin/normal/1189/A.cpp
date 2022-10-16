#include <bits/stdc++.h>
#define N 1e5+5
#define inf 0x3f3f3f3f
#define MOD1e9+7
using namespace std;
int n,one=0,zero=0;
char ch[100005];
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ch[i];
		if (ch[i]=='1') one++;
		if (ch[i]=='0') zero++;
	}
	if (one==zero)
	{
		cout<<"2"<<endl;
		cout<<ch[1]<<" ";
		for (int i=2;i<=n;i++) cout<<ch[i];
	}
	else 
	{
		cout<<"1"<<endl;
		for (int i=1;i<=n;i++) cout<<ch[i];
	}
	return 0;
}