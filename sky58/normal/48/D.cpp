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
vector <pint> ka;
int ret1[110000],ret2[110000];
int n;
int cal(void){
	int i,j,ret,it=0,ma=1000000;
	for(i=1;i<=100000;i++){
		if(it>=n) return ret;
		if(ka[it].fi!=i) return -1;
		for(j=0;;j++){
			if(it+j>=n) break;if(ka[it+j].fi>i) break;ret1[it+j]=j;
		}
		if(j>ma) return -1;if(i<2) ret=j;ma=j;it+=j;
	}
	return ret;
}

int main()
{
	int i,a;
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%d",&a);ka.pb(mp(a,i));
	}
	sort(ka.begin(),ka.end());
	int t=cal();
	if(t<0) cout<<"-1"<<endl;
	else{
		for(i=0;i<n;i++) ret2[ka[i].se]=ret1[i];
		cout<<t<<endl;
		for(i=0;i<n;i++){
			cout<<ret2[i]+1;if(i<n-1) cout<<" ";else cout<<endl;
		}
	}
	return 0;
}