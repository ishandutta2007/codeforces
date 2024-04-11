#include <bits/stdc++.h>
using namespace std;
#define Maxn 2000000
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define repV(i,v) for(auto i:v)

int n,siz;
string str;
char ans[Maxn];
set<int> s;

int main()
{
	cin>>n;
	rep(i,2000001) s.insert(i);
	
	rep(i,n)
	{
		int ki;cin>>str>>ki;
		
		while(ki--)
		{
			int k;cin>>k;k--;
			
			siz=max(siz,(int)str.size()+k);
			
			while(1)
			{
				set<int>::iterator p=s.lower_bound(k);
				if(p==s.end()) break;
				
				int x=*p;
				if(x>=str.size()+k) break;
				
				s.erase(x);
				ans[x]=str[x-k];
			}
		}
	}
	
	repV(i,s) if(i<siz) ans[i]='a';
	cout<<ans;

	return 0;
}