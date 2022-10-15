#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a,b,T;
string str;
bool C(int x)
{
	int l=0,r=x-1;
	int s=x+a*(x-1);
	if(s>T) return false;
	for(int i=n;i<n+x;i++)
		if(str[i]=='w') s+=b;
	if(s<=T) return true;
	//printf("%d %d\n\n",x,s);
	for(int i=n-1;i>=n-x+1;i--)
	{
		l++;r--;
		if(str[i]=='w') s+=b;
		if(str[i+x]=='w') s-=b;
		//printf("%d\n",s+min(l,r)*a);
		if(s+min(l,r)*a<=T) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&T);
	cin>>str;
	str+=str;
	int lb=0,rb=n+1;
	while(rb-lb>1)
	{
		int mid=(lb+rb)/2;
		if(C(mid)) lb=mid; else rb=mid;
	}
	printf("%d\n",lb);
	return 0;
}