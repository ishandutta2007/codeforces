#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int main()
{
	int n,l,r;
	cin>>n>>l>>r;
	cout<<(1<<l)+n-l-1<<" "<<(1<<(r-1))-1+(n-r+1)*(1<<(r-1))<<endl;
}