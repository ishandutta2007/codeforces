#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,m,f[5001],i,j,l;
char c;
int main()
{
	cin>>s;
	n=s.size();
	k=log2(n);
	m=n-(1<<k)+1;
	for(f[0]=1,i=1;i<=m;i++)	
	{
		for(c='z',j=0;j<(1<<k);j++)
			if(f[j])
				for(c=min(s[i+j-1],c),l=0;l<k;l++)
					f[j|(1<<l)]=1;
		putchar(c);
		for(j=0;j<(1<<k);++j)
			f[j]&=s[i+j-1]==c;
	}
		
			
}