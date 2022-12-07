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
int lev[10],lo1[10],lo2[10];
int main()
{
	int i,j,k,n,a,sum=0;
	double out=0.0;string s="";
	cin>>n>>k>>a;
	for(i=0;i<n;i++){
		cin>>lev[i]>>lo1[i];sum+=lo1[i];
	}
	for(i=0;i<k;i++) s+='a';for(i=0;i<n-1;i++) s+='b';
	do{
		int it=0;
		for(i=0;i<n;i++) lo2[i]=lo1[i];
		for(i=0;i<s.size();i++){
			if(s[i]=='a') lo2[it]=min(100,lo2[it]+10);
			else it++;
		}
		double ret=0.0;
		for(i=0;i<(1<<n);i++){
			double t=1.0;int su2=0,pe=0;
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					pe++;t*=0.01*lo2[j];
				}
				else{
					su2+=lev[j];t*=0.01*(100-lo2[j]);
				}
			}
			if(pe<=n/2) t*=1.0*a/(a+su2);
			ret+=t;
		}
//		if(lo2[0]>99 && lo2[1]>99 && lo2[2]>99) cout<<ret<<endl;
		out=max(out,ret);
	}while(next_permutation(s.begin(),s.end()));
//	cout<<out<<endl;
	printf("%.12f\n",out);
	return 0;
}