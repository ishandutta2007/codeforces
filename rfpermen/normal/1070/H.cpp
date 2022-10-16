#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<string, int> isi;
map<string, string> nix;
map<string, bool> con;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string inp;
	for(int a=0;a<n;a++)
	{
		cin>>inp;
		con.clear();
		for(int z=1;z<=inp.length();z++)
		{
			for(int b=0;b<=((int)inp.length()-z);b++)
			{
				string tmp=inp.substr(b, z);
				if(con.count(tmp)==0)
				{
					con[tmp]=1;
					isi[tmp]++;
					nix[tmp]=inp;
				}
			}
		}
	}
	int q;
	cin>>q;
	for(int a=0;a<q;a++)
	{
		cin>>inp;
		if(isi.count(inp)==0)
		{
			cout<<"0 -"<<endl;
		}
		else
		{
			cout<<isi[inp]<<" "<<nix[inp]<<endl;
		}
	}
	return 0;
}