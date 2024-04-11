# include <iostream>
# include <cstdlib>
using namespace std;
struct anim
{
	int b,m,a;
};

anim a[3001];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i].b;
	for (int i=0;i<n;i++)
		cin>>a[i].m;
	for (int i=0;i<n;i++)
		cin>>a[i].a;
	if (n==1)
	{
		cout<<a[0].b<<endl;
		return 0;
	}
	int s1=a[0].m+a[1].b;
	int s2=a[0].b+a[1].m;
	for (int i=2;i<n;i++)
	{
		int c1=s1-a[i-1].b+a[i-1].m+a[i].b;
		int c2=s2-a[i-1].m+a[i-1].a+a[i].b;
		int c3=s1+a[i].m;
		int c4=s2+a[i].m;
		s1=max(c1,c2);
		s2=max(c3,c4);
	}
	cout<<max(s1,s2)<<endl;
}