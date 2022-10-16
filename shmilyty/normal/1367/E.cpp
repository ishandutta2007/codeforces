#include<bits/stdc++.h>
using namespace std;
int t,num[27],n,k,ans;
string s;
vector<int> v;
bool check(int each,int jie) 
{
    for(int i=1;i<=26;i++) 
	{
        each-=num[i]/jie;
        if(each<=0)
            return true;
    }
    return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		cin>>s;
		ans=1;
		for(int i=1;i<=26;i++)
			num[i]=0;
		for(int i=0;i<s.size();i++)
		{
			num[s[i]-'a'+1]++;
			ans=max(ans,num[s[i]-'a'+1]);
		}
		v.clear();
		for(int i=2;i<=k;i++)
			if(k%i==0)
				v.push_back(i);
		for(int i:v)
		{
			int l=1,r=n/i;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(check(i,mid))
				{
					ans=max(ans,mid*i);
					l=mid+1;
				}
				else
					r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}