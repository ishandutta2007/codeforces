#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 100005
#define ll long long
using namespace std;

ll ans;

ll c[maxn];

int n,m;

ll sum,sum1;

bool bz[maxn];

int main(){
	scanf("%d%d",&n,&m);
	fo(i,0,n-1) {
		scanf("%I64d",&c[i]);
		sum+=c[i];
	}
	fo(i,1,m) {
		int x;
		scanf("%d",&x);
		bz[x-1]=1;
		sum1+=c[x-1];
	}
	fo(i,0,n-1) {
		if (bz[i]) {
			ans=ans+c[i] * (sum-c[i]);
		}
		else {
			ans=ans+c[i]*sum1;
			if (!bz[(i+1) % n]) ans+=c[i]*c[(i+1) % n];
			if (!bz[(i-1+n) % n]) ans+=c[i]*c[(i-1+n) % n];
		}
	}
	ans/=2;
	cout<<ans<<endl;
	return 0;
}