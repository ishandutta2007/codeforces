#include<iostream>
#include<string>
# include <queue>
#define FOR(i,n) for (int i=0;i<n;i++)
using namespace std;
int main()
 {
	 int a[10]={0};
	 int n;
	 cin>>n;
	 for (int i=0;i<n;i++)
	 {
		int b;
		cin>>b;
		a[b]++;
	 }
	 if (a[0]==0)
		 cout<<-1<<endl;
	 else
	 {
		 int y=0;
			for (int i=a[5];i>=0;i--)
			{
				if ((i*5)%3==0 && ((i*5)/3)%3==0)
				{
					y=i;
					break;
				}
			}
			if (y==0)
				cout<<0<<endl;
			else
			{
			FOR(x,y)
			cout<<5;
			FOR(x,a[0])
				cout<<0;
			cout<<endl;
			}
	 }

 }