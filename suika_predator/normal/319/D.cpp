#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int S=1000,MOD=998244353;
char str[55555],tmp[55555];
int del[55555],len;
long long h[55555],p[55555];
inline bool chk(int l1,int r1,int l2,int r2)
{
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	if(r2>len)return false;
	int s1=(h[r1]-h[l1-1]*p[r1-l1+1]%MOD+MOD)%MOD,s2=(h[r2]-h[l2-1]*p[r2-l2+1]%MOD+MOD)%MOD;
//	cout<<s1<<' '<<s2<<endl;
//	cout<<"chk "<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' '<<(s1==s2)<<endl;
	return s1==s2;
}
inline int getsuf(int r1,int r2)
{
//	cout<<"getsuf "<<r1<<' '<<r2<<endl;
	if(str[r1]!=str[r2])return 0;
	int l=1,r=r2-r1;//length
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(chk(r1-mid+1,r1,r2-mid+1,r2))l=mid;
		else r=mid-1;
	}
	return r1-l+1;
}
inline int getpre(int l1,int l2)
{
//	cout<<"getpre "<<l1<<' '<<l2<<endl;
	if(str[l1]!=str[l2])return 0;
	int l=1,r=min(l2-l1,len-l2+1);//length
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(chk(l1,l1+mid-1,l2,l2+mid-1))l=mid;
		else r=mid-1;
	}
	return l1+l-1;
}
int main()
{
	scanf("%s",str+1);
	len=strlen(str+1);
	p[0]=1;
	for(int i=1;i<=len;i++)p[i]=p[i-1]*S%MOD;
	int last=2333333;//first undeleted place
	for(int l=1;l*2<=len;l++)
	{
//		cout<<"l="<<l<<endl;
//		cout<<(str+1)<<endl;
		if(last)
		{
//			cout<<"preprocess"<<endl;
			for(int i=1;i<=len;i++)
			{
				h[i]=(h[i-1]*S+str[i])%MOD;
//				cout<<i<<' '<<h[i]<<endl;
			}
		}
		last=0;
		for(int i=l+l;i<=len;i+=l)
		{
//			cout<<"pos="<<i<<endl;
			int ll=max(getsuf(i-l,i),last),rr=getpre(i-l,i);
			if(ll+l-1<=rr)
			{
//				cout<<"delete "<<ll<<endl;
				del[ll]=1,last=ll+l;
			}
		}
		if(last)
		{
//			cout<<"qwq"<<endl;
			int top=0;
			for(int i=1;i<=len;i++)
			{
				while(del[i])
				{
					del[i]=0;
					i+=l;
				}
				tmp[++top]=str[i];
			}
			for(int i=1;i<=top;i++)str[i]=tmp[i];
			len=top;
			str[len+1]=0;
		}
	}
	printf("%s\n",str+1);
	return 0;
}