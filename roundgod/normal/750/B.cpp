#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,pos,x;
char dir[10];
int main()
{
	scanf("%d",&n);
	pos=0;
	bool f=true;
	for(int i=0;i<n;i++)
	{
		scanf("%d%s",&x,dir);
		if(pos==0&&dir[0]!='S') f=false;
		if(pos==20000&&dir[0]!='N') f=false;
		if(dir[0]=='S') pos=pos+x;
		if(dir[0]=='N') pos=pos-x;
		if(pos<0||pos>20000) f=false;
	}
	if(pos!=0) f=false;
	if(f) puts("YES"); else puts("NO");
	return 0;
}