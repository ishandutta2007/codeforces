#include<bits/stdc++.h>
using namespace std;
int n,v[10];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<10;i++)
		v[i]=2;
	while(n--)
	{
		char c[2];
		int t;
		scanf("%s %d",c,&t);
		if(c[0]=='|')
			for(int i=0;i<10;i++)
				if(t&(1<<i))
					v[i]=1;
		if(c[0]=='&')
			for(int i=0;i<10;i++)
				if(!(t&(1<<i)))
					v[i]=0;
		if(c[0]=='^')
			for(int i=0;i<10;i++)
				if(t&(1<<i))
					v[i]^=1;		
	}	
	int v1=0,v2=0,v3=0;
	for(int i=0;i<10;i++)
	{
		if(v[i]==0)
			v1|=(1<<i);
		if(v[i]==1)
			v2|=(1<<i);
		if(v[i]==3)
			v3|=(1<<i);
	}
	cout<<3<<endl;
	cout<<"| "<<v2<<endl;
	cout<<"& "<<(1023^v1)<<endl;
	cout<<"^ "<<v3<<endl;
	return 0;
}