#include<iostream>
#include<cctype>
#include<string>
using namespace std;

typedef long long LL;
int c,Hb,Hs,Hc,Nb,Ns,Nc,Pb,Ps,Pc;
LL L,R,Rb;
string s;

LL Max(LL A,LL B) {return A>B?A:B;}
int check(LL x)
{
	LL NDb,NDs,NDc;
	NDb=Max(x*Nb-Hb,0);NDs=Max(x*Ns-Hs,0);NDc=Max(x*Nc-Hc,0);
	return (NDb*Pb+NDs*Ps+NDc*Pc<=Rb);
}

int main()
{
	cin>>s;
	for (int i=0;i<s.length();i++)
		if (s[i]=='B') Nb++;else if (s[i]=='S') Ns++;else Nc++;
	cin>>Hb>>Hs>>Hc>>Pb>>Ps>>Pc>>Rb;
	L=0;R=Rb+200;
	while (L+1<R)
	{
		LL Mid=(L+R)>>1;
		if (check(Mid)) L=Mid;else R=Mid;
	}
	cout<<L<<endl;
	return 0;
}