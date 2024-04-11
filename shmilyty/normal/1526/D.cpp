#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,num[5],tree[400001],p[100001];
pair<int,int> a[100001],b[100001];
string s,str[5]={"","A","N","T","O"};
map<char,int> dic;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		tree[i]+=y;
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
void solve()
{
	cin>>s;
	n=s.size();
	num[1]=num[2]=num[3]=num[4]=0;
	for(int i=0;i<s.size();i++)
		num[dic[s[i]]]++;
	for(int i=0;i<s.size();i++)
		a[i+1]={dic[s[i]],i+1};
	sort(a+1,a+1+n);
	int c[]={0,1,2,3,4};
	int ans=0;
	string anss="";
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=4;i++)
			for(int l=1;l<=num[c[i]];l++)
			{
				cnt++;
				b[cnt]={c[i],cnt}; 
			}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++)
			p[a[i].second]=b[i].second;
		for(int i=n;i;i--)
		{
			sum+=query(p[i]);
			update(p[i],1);
		}
		for(int i=0;i<=2*n;i++)
			tree[i]=0;
		if(sum>=ans)
		{
			ans=sum;
			anss="";
			cnt=0;
			for(int i=1;i<=4;i++)
				for(int l=1;l<=num[c[i]];l++)
				{
					cnt++;
					anss+=str[c[i]];
				}
		}
	}while(next_permutation(c+1,c+5));
	cout<<anss<<endl;
}
signed main()
{	
	t=read();
	dic['A']=1;
	dic['N']=2;
	dic['T']=3;
	dic['O']=4;
	while(t--)
		solve();
	return 0;
}