#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s,s1,s2;
	int pos1,pos2,r=0;
	
	cin>>s>>s1>>s2;
	
	pos1 = s.find(s1);
	if(pos1!=-1)
	{
		pos2 = s.find(s2,pos1+s1.length());
		if(pos2!=-1) r+=1;
	}
	
	reverse(s.begin(),s.end());
	
	pos1 = s.find(s1);
	if(pos1!=-1)
	{
		pos2 = s.find(s2,pos1+s1.length());
		if(pos2!=-1) r+=2;
	}
	
	if(r==0) cout<<"fantasy";
	if(r==1) cout<<"forward";
	if(r==2) cout<<"backward";
	if(r==3) cout<<"both";
	
	cout<<endl;
	
	return 0;
}