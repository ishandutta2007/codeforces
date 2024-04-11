#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
	cin>>str;
	n=str.size();
	int cnta=0,cntb=0,cntc=0,flag=0;
	for(int i=0;i<n;i++)
	{
		if(flag==0)
		{
			if(str[i]=='a') cnta++;
			else if(str[i]=='c') {puts("NO"); return 0;}
			else {flag=1; cntb=1; continue;} 
		}
		else if(flag==1)
		{
			if(str[i]=='b') cntb++;
			else if(str[i]=='a') {puts("NO"); return 0;}
			else {flag=2; cntc=1; continue;}
		}
		else
		{
			if(str[i]!='c') {puts("NO"); return 0;}
			cntc++;
		}
	}
	if((cntc==cnta||cntc==cntb)&&cnta!=0&&cntb!=0&&cntc!=0) puts("YES"); else puts("NO");
	return 0;
}