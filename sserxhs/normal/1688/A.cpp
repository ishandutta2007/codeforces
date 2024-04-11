#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int x;
		cin>>x;
		cout<<(x==(x&-x)?x+1+(x==1):x&-x)<<'\n';
	}
}