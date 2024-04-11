#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main()
{
	int n,i,a;
	cin>>n;
	for(i=0;i<n;i++)
	{
	cin>>a;
	if(a<180&&360%(180-a)==0)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<endl;
	}
}