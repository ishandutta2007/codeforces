#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include<sstream>
#include<queue>
#define mp make_pair
#define pb push_back
#define pw(x) (1ull<<(x))
#define CC(x) cout << (x) << endl
#define S stringstream
#define m0(x) memset(x,0,sizeof(f))


using namespace std;


int n,a[222222],k[222222];
long long l,r,c;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d%d",&k[i],&a[i]);
	l=0;
	r=2e9;
	while (l<r){
		c=(l+r)/2;
		int be=0;
		for (int i=0;i<n;i++){
			if (k[i]>=c){
				be=1;
				break;
			}
			if (c-k[i]<25&&a[i]>pw((c-k[i])*2)){
				be=1;
				break;
			}
		}
		if (be)l=c+1;else r=c;
	}
	cout << l << endl;
	return 0;
}