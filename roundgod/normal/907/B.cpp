#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str[11];
int x,y;
int main()
{
	for(int i=0;i<11;i++)
		getline(cin,str[i]);
	scanf("%d%d",&x,&y);
	int numx=(x-1)%3,numy=(y-1)%3;
	bool f=false;
	int x0=numx*4,y0=numy*4;
	for(int i=x0;i<x0+3;i++)
		for(int j=y0;j<y0+3;j++)
			if(str[i][j]=='.') {f=true; str[i][j]='!';}
	if(!f)
	{
		for(int i=0;i<11;i++)
			for(int j=0;j<11;j++)
				if(str[i][j]=='.') str[i][j]='!';
	}
	for(int i=0;i<11;i++)
		cout<<str[i]<<endl;
	return 0;
}