#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[2010];
int main()
{
	int n,k,ans=0;
	cin>>n>>k;
	for(int n1=1;n1<=n;n1++)
		cin>>num[n1];
	sort(num+1,num+n+1);
	for(int n1=n;n1>=1;n1-=k)
		ans+=num[n1]-1;;
	cout<<ans*2<<endl;
		
}