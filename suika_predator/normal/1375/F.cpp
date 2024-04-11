#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long a[5],b[5];
pair<long long,int> srt[5];
long long solve(long long x,long long y,long long z,int last)
{
	if(y-x==z-y)return z-y;
	if(y-x>z-y)
	{
		long long diff=(y-x)-(z-y);
		if(last==3)
		{
			if(y-x==3*(z-y))return z-y;
			if(z-x>diff)return diff;
			else return z-x;
		}
		else return diff;
	}
	else
	{
		if(z-x==3*(y-x)&&last==3)return z-x;
		return z-y;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=1;i<=3;i++)
	{
		cin>>a[i];
	}
	cout<<"First"<<endl;
	int t=0,last=0;
	while(!(a[1]==a[2]||a[1]==a[3]||a[2]==a[3]))
	{
		for(int i=1;i<=3;i++)srt[i]=make_pair(a[i],i);
		sort(srt+1,srt+4);
		for(int i=1;i<=3;i++)
		{
			b[i]=srt[i].first;
			if(t==srt[i].second)last=i;
		}
		long long w=solve(b[1],b[2],b[3],last);
		cout<<w<<endl;
		cin>>t;
		if(t==0)return 0;
		a[t]+=w;
//		cerr<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
	}
	return 0;
}