#include<bits/stdc++.h>
const int N=300005;
using namespace std;
typedef long long ll;
int n,x,y;
ll ans,ls;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		y=min((ll)x>>1,ls);
		ls-=y,x-=y*2,ans+=y;
		if(ls)ls+=x;
		else ans+=x/3,ls=x%3;
	}printf("%lld",ans);
}