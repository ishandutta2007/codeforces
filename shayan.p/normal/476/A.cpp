#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main()
{
	int n,i,j,m;
	cin>>n>>m;
	int two=n/2;
	int one=n%2;
	int q=(m-((one+two)%m))%m;
	if(q<=two)
	cout<<one+two+q;
	else
	cout<<-1;
}