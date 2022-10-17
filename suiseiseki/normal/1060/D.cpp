#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int Left[100005],Right[100005];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&Left[i],&Right[i]);
		ans+=Left[i]+Right[i]+1;
	}
	sort(Left+1,Left+1+n);
	sort(Right+1,Right+1+n);
	for(int i=1;i<=n;i++){
		ans-=mn(Left[i],Right[i]);
	}
	cout<<ans<<endl;
	return 0;
}