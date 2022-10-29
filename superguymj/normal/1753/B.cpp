#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mp make_pair

using namespace std;
const int N=500005;
int n,x,cnt[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint(),x=getint();
	rep(i,1,n) ++cnt[getint()];
	rep(i,1,x-1)
	{
		int p=cnt[i];
		if(p%(i+1)) return puts("No"),0;
		cnt[i+1]+=p/(i+1);
	}
	puts("Yes");
	return 0;
}