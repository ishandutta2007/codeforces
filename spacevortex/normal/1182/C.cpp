#include<bits/stdc++.h>
using namespace std;
int n,tot1=0,tot2=0,ans;
const int N=2e5+50;
struct Data
{
	int num;
	char las;
	string s;
}da[N];
struct Pair
{
	Data a,b;
}P1[N],P2[N];
inline bool cmp(const Data &a,const Data &b)
{
	if(a.num!=b.num) return a.num<b.num;
	else return a.las<b.las;
}
Data pre;
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	int i,j,len;
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>da[i].s;
		len=da[i].s.size();
		for(j=0;j<len;j++)
		{
			if(da[i].s[j]=='a'||da[i].s[j]=='e'||da[i].s[j]=='i'||da[i].s[j]=='o'||da[i].s[j]=='u')
			{
				da[i].num++;
				da[i].las=da[i].s[j];
			}
		}
	}
	sort(da+1,da+n+1,cmp);
	for(i=1;i<=n;)
	{
		if(i<n&&da[i].num==da[i+1].num&&da[i].las==da[i+1].las) 
		{
			P2[++tot2]=(Pair){da[i],da[i+1]};
			i+=2;
		}
		else
		{
			if(da[i].num==pre.num) 
			{
				P1[++tot1]=(Pair){pre,da[i]},pre.num=0;
			}
			else pre=da[i];
			i++;
		}
	}
	//printf("%d %d\n",tot1,tot2);
	while(tot2>=tot1+2) 
	{
		P1[tot1+1]=P2[tot2];
		tot2--,tot1++;
	}
	ans=min(tot1,tot2);
	cout<<ans<<endl;
	for(i=1;i<=ans;i++)
	{
		//cout<<"!!!"<<endl;
		cout<<P1[i].a.s<<" "<<P2[i].a.s<<endl;
		cout<<P1[i].b.s<<" "<<P2[i].b.s<<endl;
	}
	return 0;
}