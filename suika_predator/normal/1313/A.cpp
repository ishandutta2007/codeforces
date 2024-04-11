#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		int cnt=0;
		if(a>=1)a--,cnt++;
		if(b>=1)b--,cnt++;
		if(c>=1)c--,cnt++;
		if(a>=2&&b>=2&&c>=2)a-=2,b-=2,c-=2,cnt+=3;
		else if(max(a,max(b,c))>=2&&min(a,min(b,c))==1)
		{
			if(a>=2&&b>=1&&c>=1)cnt+=2,a-=2,b--,c--;
			if(b>=2&&a>=1&&c>=1)cnt+=2,b-=2,a--,c--;
			if(c>=2&&a>=1&&b>=1)cnt+=2,c-=2,a--,b--;
		}
		else
		{
//			cerr<<"QAQ"<<endl;
			if(a>=1&&b>=1)a--,b--,cnt++;
			if(a>=1&&c>=1)a--,c--,cnt++;
			if(b>=1&&c>=1)b--,c--,cnt++;
		}
		if(a>=1&&b>=1&&c>=1)cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}