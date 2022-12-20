#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define PB push_back
int main()
{
	int n;
	int num[2];
	num[0]=0;
	num[1]=0;
	cin>>n;
	vector<int> v;
	bool correct=1;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		if(v.size()>0&&v[0]==a)
			num[0]++;
		else if(v.size()>1&&v[1]==a) 
			num[1]++; 
		else
		{
			if(v.size()<2)
			{
			v.push_back(a);
			num[v.size()-1]++;
			}
			else
			correct=0;
		}
	}
	if(correct==0)
	cout<<"NO";
	else
	{
	if(num[0]!=num[1])
	cout<<"NO";
	else
	cout<<"YES"<<endl<<v[0]<<" "<<v[1];
	}
}