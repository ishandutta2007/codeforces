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
int ka[1100];
int main()
{
	int i,n;
	double ma=1e10,mi=0.0;cin>>n;
	for(i=0;i<n;i++) scanf("%d",&ka[i]);
	for(i=0;i<n;i++){
		ma=min(ma,10.0*(ka[i]+1)/(i+1));
		mi=max(mi,10.0*ka[i]/(i+1));
//		cout<<ma<<' '<<mi<<endl;
	}
	int a=(int)((ma-1e-6)*(n+1)/10),b=(int)((mi+1e-6)*(n+1)/10);
//	cout<<ma<<' '<<mi<<' '<<a<<' '<<b<<endl;
	if(a!=b) cout<<"not unique"<<endl;
	else{cout<<"unique"<<endl;cout<<a<<endl;}
	return 0;
}