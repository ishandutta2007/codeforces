#include<bits/stdc++.h>
using namespace std;
map<string,int> shirts;
string x[5][5]={
{"S","M","L","XL","XXL"},
{"M","L","S","XL","XXL"},
{"L","XL","M","XXL","S"},
{"XL","XXL","L","M","S"},
{"XXL","XL","L","M","S"},
};
int main()
{
	cin>>shirts["S"]>>shirts["M"]>>shirts["L"]>>shirts["XL"]>>shirts["XXL"];
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		string s;
		cin>>s;
		int a;
		int t=0;
		if(s=="S")
			a=0;
		if(s=="M")
			a=1;
		if(s=="L")
			a=2;
		if(s=="XL")
			a=3;
		if(s=="XXL")
			a=4;
		while(shirts[x[a][t]]==0)
			t++;
		cout<<x[a][t]<<endl;
		shirts[x[a][t]]--;
	}
	return 0;
}