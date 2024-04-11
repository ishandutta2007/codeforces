#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k;
bool findsum(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x=x/10;
		if(s>10) return false;
	}
	if(s==10) return true; else return false;
}
int main()
{
	scanf("%d",&k);
	int i=19;
	while(true)
	{
		if(findsum(i)) k--;
		if(k==0) break;
		i++;
	}
	printf("%d\n",i);
	return 0;
}