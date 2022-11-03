#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

vector<ll> bs;
ll a,b;
int main()
{
	cin>>a>>b;
	bs.push_back(b);
	while(b>a)
	{
		if((b%10)==1) b=((b-1)/10);
		else if(((b%10)%2)==0) b/=2;
		else return puts("NO"),0;
		bs.push_back(b);
		if(a==b)
		{
			puts("YES");
			cout<<bs.size()<<endl;
			sort(bs.begin(),bs.end());
			for(int i=0;i<bs.size();i++)cout<<bs[i]<<((i==bs.size()-1)?'\n':' ');
			return 0;
		}
	}
	return puts("NO"),0;
}