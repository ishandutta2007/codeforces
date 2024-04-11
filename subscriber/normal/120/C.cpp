#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,k,a[1111],f[1111],ans=0;

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)ans+=a[i];
	for(;;){
		int o=-1,l;
		for (int i=0;i<n;i++)if (f[i]<3&&a[i]>o)o=a[i],l=i;
		if (o<k)break;
		ans-=k;
		a[l]-=k;
		f[l]++;
	}
	CC(ans);
	return 0;
}