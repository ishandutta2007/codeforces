/*
LANG: C++
ID: AnilKishore (RedAnt/FlyingAnt)
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
#define SI(x) scanf("%d",&x)

#define MX 2000005

char sb[MX], sn[MX];
LL m, b, cb, r, f;

int main()
{
	int i,j,k,lb,ln;
	scanf("%s%s%d",sb, sn, &k);
	m=(LL)k;
	//cout<<sb<<":"<<sn<<":"<<m<<endl;

	b = 0; lb = strlen(sb); ln = strlen(sn);
	for(i=0;i<lb;i++)
	{
		j = sb[i]-'0';
		b = ( b * 10 + j ) % m;
	}

	for(i=ln-1;sn[i]=='0';i--){}
	sn[i]--;
	for(i++;i<ln;i++) sn[i]='9';

	//cout<<"sn-1 = "<<sn<<" , b = "<<b<<" , b10 = "<<b10<<endl;

	for(cb=b,r=1,i=ln-1;i>=0;i--)
	{
		j = sn[i]-'0';

		f=cb;
		while(j)
		{
			if(j&1) r=(r*f)%m;
			j>>=1;
			f=(f*f)%m;
		}

		f = cb; cb = 1;
		f = (f*f)%m; cb=(cb*f)%m;
		f = (f*f)%m; f = (f*f)%m; cb=(cb*f)%m;
	}

	r = ( r * ( b - 1 + m ) ) % m;

	if(r==0) r = m;
	k = (int)r;
	printf("%d\n",k);
	//cout<<r<<endl;
	return 0;
}