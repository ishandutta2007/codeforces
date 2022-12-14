#include<stdio.h>
# include <iostream>
# include <algorithm>
# include <string>
using namespace std;
int a[1000][1000];
int  main()
 {
     int n;
	 cin>>n;
	 int max=n*n;
	 int min=1;
	 int loc[1000]={0};
	 for (int i=0;i<n;i++)
	 {
		for (int x=0;x<n;x++)
		{
			a[x][loc[x]]=min;
			loc[x]++;
			a[x][loc[x]]=max;
			loc[x]++;
			min++;
			max--;
		}
	 
	 
	 }
	 for (int i=0;i<n;i++)
	 {
		 for (int x=0;x<n;x++)
		 {
			cout<<a[i][x];
			if (x<n-1)
				cout<<" ";
		 
		 }
		 cout<<endl;
	 }
 }