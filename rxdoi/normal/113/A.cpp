#include<cstdio>
#include<string>
#include<iostream>
#define ERROR {puts("NO");return 0;}
using namespace std;

const int Maxn=1e5+19;
string s[Maxn];
int is_F,n,now,cnt,tmp,noun;

int main()
{
	while (cin>>s[++n]);n--;
	now=1;tmp=-1;
	for (int i=1;i<=n;i++)
	{
		int Flag=0,x,y;
		int Len=s[i].length();
		string t="";
		for (int j=5;j>=0;j--) if (Len>=j) t=t+s[i][Len-j-1];
		Len=t.length();
		if (Len>=4&&t.substr(Len-4,4)=="lios") {if (i==1) tmp=1;x=1;Flag=1;y=1;}	
		if (Len>=5&&t.substr(Len-5,5)=="liala") {if (i==1) tmp=2;x=2;Flag=1;y=1;}		
		if (Len>=3&&t.substr(Len-3,3)=="etr") {if (i==1) tmp=1;x=1;Flag=1;y=2;}		
		if (Len>=4&&t.substr(Len-4,4)=="etra") {if (i==1) tmp=2;x=2;Flag=1;y=2;}		
		if (Len>=6&&t.substr(Len-6,6)=="initis") {if (i==1) tmp=1;x=1;Flag=1;y=3;}
		if (Len>=6&&t.substr(Len-6,6)=="inites") {if (i==1) tmp=2;x=2;Flag=1;y=3;}
		if (!Flag) ERROR;
		if (x!=tmp) ERROR;
		if (n!=1)
		{
			if (now==1) 
			{
				if (y==3) ERROR;
				if (y==2) now=2,noun=1;
			}
			else 
			if (now==2)
			{
				if (y==2||y==1) ERROR;
				if (y==3) now=3;
			}
			else 
			if (now==3) if (y!=3) ERROR;
		}
	}
	if (n!=1&&noun!=1) ERROR;
	puts("YES");
}