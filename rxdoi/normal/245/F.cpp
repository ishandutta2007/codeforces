#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

const int Maxn=5e6+19;
int Day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int n,m,A[Maxn],cnt;
char cc[Maxn];
string s,t[Maxn];

int main()
{
	cin>>n>>m;
	scanf("\n");
	while (getline(cin,s)) 
	{
		t[cnt]=s.substr(0,19);
		for (int i=0;i<=20;i++) s[i]-='0';
		int Mo=s[5]*10+s[6];
		int D=s[8]*10+s[9];
		int H=s[11]*10+s[12];
		int M=s[14]*10+s[15];
		int S=s[17]*10+s[18];
		int x=0;
		for (int i=1;i<Mo;i++) x+=Day[i]*24*60*60;
		for (int i=1;i<D;i++) x+=24*60*60;
		for (int i=1;i<=H;i++) x+=60*60;
		for (int i=1;i<=M;i++) x+=60;
		x+=S;
		A[cnt++]=x;
	}
	for (int i=m-1;i<cnt;i++)
		if (A[i]-A[i-m+1]<n) 
		{
			cout<<t[i];return 0;
		}
	puts("-1");
}