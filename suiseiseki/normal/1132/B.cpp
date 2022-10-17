#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 300000
#define ll long long
int a[Maxn+5];
int q[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	ll sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&q[i]);
		cout<<sum-a[q[i]]<<endl;
	}
	return 0;
}