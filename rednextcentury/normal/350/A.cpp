#include<iostream>
#include<string>
# include <algorithm>
#define FOR(i,n) for (int i=0;i<n;i++)
using namespace std;
int a[10000];
int b[10000];
int main()
 {
        int n,m;
		cin>>n>>m;
		int mina=1000000;
		int minb=1000000;
		int maxa=-1;
		int maxb=-1;
		FOR(i,n)
		{
			cin>>a[i];
			if (a[i]<mina)
				mina=a[i];
			if (a[i]>maxa)
				maxa=a[i];
		}
		FOR(i,m)
		{
			cin>>b[i];
			if (b[i]<minb)
				minb=b[i];
			if (b[i]>maxb)
				maxb=b[i];
		}
		if (mina*2<minb && maxa<minb)
			cout<<max(mina*2,maxa)<<endl;
		else
			cout<<-1<<endl;
 }