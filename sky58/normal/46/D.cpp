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
int pa[110],ca[110],le[110];
int l,ba,f,inf=1000000000;
int de(int a){
	if(pa[a]==-1) return 0;else return pa[a]+le[a]+ba;
}
int cal(int a){
	int ret=inf,i,j;
	for(i=0;i<110;i++){
		int k=de(i),fl=1;
//		if(i<5) cout<<k<<'a'<<endl;
		for(j=0;j<110;j++){
			if(pa[j]<0) continue;
			if(k>=pa[j] && pa[j]+le[j]+ba>k) fl=0;
			if(pa[j]>=k && k+a+f>pa[j]) fl=0;
		}
		if(l<k+a) fl=0;
		if(fl>0) ret=min(ret,k);
	}
	return ret;
}
int main()
{
	int i,j,n,a,b;
	for(i=0;i<110;i++) pa[i]=ca[i]=le[i]-1;
	cin>>l>>ba>>f;cin>>n;
	for(i=0;i<n;i++){
//		if(i==1) cout<<pa[0]<<' '<<le[0]<<endl;
		cin>>a>>b;
		if(a==2){pa[ca[b-1]]=-1;le[ca[b-1]]=-1;}
		else{
			le[i]=b;int t=cal(b);
			if(t>=inf) cout<<"-1"<<endl;
			else{
				int fl=1;cout<<t<<endl;
				for(j=0;j<110 && fl>0;j++){
					if(pa[j]<0){
						pa[j]=t;le[j]=b;ca[i]=j;fl=0;
					}
				}
			}
		}
	}
	return 0;
}