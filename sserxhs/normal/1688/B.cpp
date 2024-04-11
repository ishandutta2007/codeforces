//114514min
#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		if (*max_element(all(a)))
		{
			for (int &x:a) x=x?__lg(x&-x):1e9;
			if (*min_element(all(a))) cout<<*min_element(all(a))+n-1<<'\n';
			else
			{
				int r=0;
				for (int x:a) r+=!!x;
				cout<<r<<'\n';
			}
		} else cout<<"-1\n";
	}
}