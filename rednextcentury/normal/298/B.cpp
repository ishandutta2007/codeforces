# include <iostream>
# include <string>
using namespace std;
int main ()
{
string s;
int t,x1,y1,x2,y2;
int S=0,W=0,E=0,N=0;
cin>>t>>x1>>y1>>x2>>y2;

cin>>s;
if (x1>x2)
{
	W=x1-x2;
}

else
{
	E=x2-x1;
}
if (y1>y2)
{
	S=y1-y2;
}
else
{
	N=y2-y1;
}
int ans=-5;
for (int i=0;i<s.length();i++)
{

	if (s[i]=='S')
		S--;
	if (s[i]=='N')
		N--;
	if (s[i]=='W')
		W--;
	if (s[i]=='E')
		E--;
	if (S<=0 && E<=0 && W<=0 && N<=0)
	{
	ans=i+1;
	break;
	
	}
}
if (ans>=0)
	cout<<ans<<endl;
else
	cout<<-1<<endl;
}