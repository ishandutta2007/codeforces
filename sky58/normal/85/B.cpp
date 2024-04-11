#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
lint c1[110000],c2[110000],c3[110000];
int main()
{
	int i,k1,k2,k3,t1,t2,t3,f1=0,f2=0,f3=0,n;lint out=0,m;
	for(i=0;i<110000;i++) c1[i]=c2[i]=c3[i]=0;
	cin>>k1>>k2>>k3;cin>>t1>>t2>>t3;cin>>n;
	for(i=0;i<n;i++){
		scanf("%lld",&m);
		lint x=max(m,c1[f1])+t1;c1[f1]=x;f1=(f1+1)%k1;
		x=max(x,c2[f2])+t2;c2[f2]=x;f2=(f2+1)%k2;
		x=max(x,c3[f3])+t3;c3[f3]=x;f3=(f3+1)%k3;
		out=max(out,x-m);
	}
	cout<<out<<endl;
	return 0;
}