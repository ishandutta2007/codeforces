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
const int x[4]={1,2,3,5};
int main()
{
	int n,k,n1,n2;
	cin>>n>>k;
	cout<<(6*n-1)*k<<endl;
	for(n1=0;n1<n;n1++)
	{
		for(n2=0;n2<4;n2++)
			cout<<(x[n2]+6*n1)*k<<' ';
		cout<<endl;
	}
}