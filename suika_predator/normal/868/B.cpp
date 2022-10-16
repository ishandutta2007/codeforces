#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int h,m,s,t1,t2;
int main()
{
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	double mm=m+s/60.0,hh=h+mm/60.0;
	mm/=5;
	double ss=s/5.0;
	if(hh>=12)hh-=12;
	if(t1>t2)swap(t1,t2);
	//cout<<hh<<' '<<mm<<' '<<ss<<' '<<t1<<' '<<t2<<endl;
	if(t1<hh&&t1<mm&&t1<ss&&t2>hh&&t2>mm&&t2>ss)return printf("YES\n"),0;
	if(hh<t1)hh+=12;
	if(mm<t1)mm+=12;
	if(ss<t1)ss+=12;
	t1+=12;
	swap(t1,t2);
	//cout<<hh<<' '<<mm<<' '<<ss<<' '<<t1<<' '<<t2<<endl;
	if(t1<hh&&t1<mm&&t1<ss&&t2>hh&&t2>mm&&t2>ss)return printf("YES\n"),0;
	printf("NO\n");
	return 0;
}