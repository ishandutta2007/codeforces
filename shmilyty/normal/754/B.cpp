#include<bits/stdc++.h>
using namespace std;
string s[4];
int tx[]={0,1,1,1,0,0,-1,-1,-1};
int ty[]={0,1,0,-1,1,-1,1,0,-1};
bool judge(int x,int y)
{
	if(x>=0&&x<4&&y>=0&&y<4)
		return 1;
	return 0;
}
int calc(char c)
{
	if(c=='.')
		return 0;
	if(c=='x')
		return 1;
	return 114514;
}
int main()
{
	for(int i=0;i<4;i++)
		cin>>s[i];
	for(int i=0;i<4;i++)
		for(int l=0;l<4;l++)
			for(int j=1;j<=8;j++)
			{
				int x=i+tx[j];
				int y=l+ty[j];
				int x1=x+tx[j];
				int y1=y+ty[j];
//				cout<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
				if(!judge(x,y)||!judge(x1,y1))
					continue;
//				cout<<i<<" "<<l<<" "<<j<<endl;
				int sum=calc(s[i][l])+calc(s[x][y])+calc(s[x1][y1]);
				if(sum==2)
				{
					cout<<"YES";
					return 0;
				}
			}
	cout<<"NO";
	return 0;			
}