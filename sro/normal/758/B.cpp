#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

char colour[4],all[12345];
int cr,cb,cy,cg,brksum=0,ornot=0;
vector<int> weid3;vector<char> ohno;
map<char,int> mci,mc2;
int main()
{
	scanf("%s",all);
	memset(colour,'.',sizeof(colour));
	int len=strlen(all);
	for(int i=0;i<len;i++)
		if(all[i]!='!')
			colour[i%4]=all[i]/*,mci[all[i]]++*/;
//		else brksum++;
	for(int i=0;i<4;i++)if(colour[i]=='.')ornot=1;
						else ohno.push_back(colour[i]);
	vector<char> c;
	if(ornot){
		bool R=0,B=0,Y=0,G=0;
		for(int i=0;i<ohno.size();i++)
			if(ohno[i]=='R')R=1;
			else if(ohno[i]=='B')B=1;
			else if(ohno[i]=='Y')Y=1;
			else if(ohno[i]=='G')G=1;
		if(!R)c.push_back('R');
		if(!B)c.push_back('B');
		if(!Y)c.push_back('Y');
		if(!G)c.push_back('G');
	}
	int js=0;
	for(int j=0;j<len;j++)
	{
		if(all[j]=='!')
		{
			if(colour[j%4]!='.')
				mc2[colour[j%4]]++;
			else
				colour[j%4]=c[js++],mc2[colour[j%4]]++;
		}
	}
	printf("%d %d %d %d\n",mc2['R'],mc2['B'],mc2['Y'],mc2['G']);
	return 0;
}