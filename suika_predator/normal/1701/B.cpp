#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> ans;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)continue;
			int j=i;
			while(j<=n)ans.push_back(j),j*=2;
		}
		cout<<2<<endl;
		for(auto z:ans)cout<<z<<' ';
		cout<<endl;
	}
	
	return 0;
}