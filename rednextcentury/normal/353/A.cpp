#include<iostream>
#include<algorithm>
using namespace std;
#include<cstring>
#include<math.h> 

int main()
{
	int a[1000]={0};
	int b[1000]={0};
	int s[10]={0};
	int n;
	int t1=0;
	int t2=0;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		t1+=a[i];
		t2+=b[i];
		s[abs(a[i]-b[i])]++;
	}
	if (t1%2==0 && t2%2==0)
		cout<<0<<endl;
	else if ((t1%2==0 && t2%2!=0) || (t1%2!=0 && t2%2==0))
		cout<<-1<<endl;
	else
	{
		if (s[3]>0 || s[5]>0 || s[1]>0)
			cout<<1<<endl;
		else
			cout<<-1<<endl;
	}
}