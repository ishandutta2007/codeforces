#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=a[i]-1;
	}
	sort(a+1,a+1+n);
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]>now){
			now++;
		}
	}
	cout<<ans-(a[n]-now)<<endl;
	return 0;
}