#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<deque>
using namespace std;
string s;
int cr[666];
int bak[666];
deque<int>q;
int sav[500000];
bool check(int n,int ct)
{
	int head=1,tail=0;
	if(ct%2==0)
	{
		for(int i=(int)'A';i<=(int)'Z';++i)
			if(cr[i]%2)return false;
		for(int i=(int)'a';i<=(int)'z';++i)
			if(cr[i]%2)return false;
		for(int i=(int)'0';i<=(int)'9';++i)
			if(cr[i]%2)return false;
		cout<<n<<endl;
		int j=(int)'0';
		for(int i=1;i<=n;++i)
		{
			q.resize(0);
			int need=ct;
			while(need>0)
			{
				if(cr[j]<=0)
				{
					++j;
					continue;
				}
				int p=min(need,cr[j]);
				for(int k=1;k<=p>>1;++k)
					q.push_front(j);
				for(int k=1;k<=p>>1;++k)
					q.push_back(j);
				cr[j]-=p;
				need-=p;
			}
			int sz=q.size();
			for(int p=0;p<sz;++p)
				cout<<(char)(q[p]);
			cout<<" ";
		}
		return true;
	}else{
		for(int i=(int)'0';i<=(int)'z';++i)
			bak[i]=cr[i];
		int cnt=0;
		for(int i=(int)'0';i<=(int)'z'&&cnt<n;++i)
			if(bak[i]%2)
			{
				sav[++tail]=i;
				bak[i]--;
				cnt++;
			}
		for(int i=(int)'0';i<=(int)'z'&&cnt<n;++i)
		{
			if(bak[i]>0)
			{
				int p=min(n-cnt,bak[i]);
				for(int j=1;j<=p;++j)sav[++tail]=i;
				bak[i]-=p;
				cnt+=p;
			}
		}
		//cout<<"*"<<endl;
		for(int i=(int)'A';i<=(int)'Z';++i)
			if(bak[i]%2)return false;
		for(int i=(int)'a';i<=(int)'z';++i)
			if(bak[i]%2)return false;
		for(int i=(int)'0';i<=(int)'9';++i)
			if(bak[i]%2)return false;
		//cout<<"*"<<endl;
		cout<<n<<endl;
		int j=(int)'0';
		for(int i=1;i<=n;++i)
		{
			q.resize(0);
			q.push_back(sav[head++]);
			int need=ct-1;
			while(need>0)
			{
				if(bak[j]<=0)
				{
					++j;
					continue;
				}
				int p=min(need,bak[j]);
				//cout<<j<<endl;
				for(int k=1;k<=p>>1;++k)
					q.push_front(j);
				for(int k=1;k<=p>>1;++k)
					q.push_back(j);
				bak[j]-=p;
				need-=p;
			}
			for(int p=0;p<ct;++p)
				cout<<(char)(q[p]);
			cout<<" ";
		}
		return true;
	}
}
int main()
{
	int k;
	cin>>k>>s;
	for(int i=0;i<k;++i)
		cr[(int)s[i]]++;
	for(int i=1;i<=k;++i)
		if(k%i==0)if(check(i,k/i))return 0;
	return 0;
}