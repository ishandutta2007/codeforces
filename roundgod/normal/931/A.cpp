#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	int len=max(a-b,b-a);
	if(len&1) printf("%d\n",(len/2+1)*(len/2)/2+(len/2+2)*(len/2+1)/2);
	else printf("%d\n",len/2*(len/2+1));
	return 0;
}