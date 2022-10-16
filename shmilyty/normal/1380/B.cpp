#include<bits/stdc++.h>
using namespace std;
int t,rn,sn,pn;
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		rn=sn=pn=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
			switch(s[i])
			{
				case 'R':{
					rn++;
					break;
				}
				case 'S':{
					sn++;
					break;
				}
				case 'P':{
					pn++;
					break;
				}
			}
		int maxx=max(rn,max(sn,pn)),n=s.size();
		if(maxx==rn)
			while(n--)
				cout<<"P";
		else
		if(maxx==sn)
			while(n--)
				cout<<"R";
		else
		if(maxx==pn)
			while(n--)
				cout<<"S";
		cout<<endl;
	}
	return 0;
}