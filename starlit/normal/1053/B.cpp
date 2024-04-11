#include<bits/stdc++.h>
#define N 300005
using namespace std;
typedef long long ll;
int n,a[N],s[N],od[2],mx;
ll x,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		for(;x;x>>=1)
		a[i]+=(x&1);
    }
    for(int i=1,j=0;i<=n;i++){
		s[i]=s[i-1]+a[i];
		mx=0;
		for(int k=i;k&&k>i-130;k--){
			mx=max(mx,a[k]);
			if((s[i]-s[k-1])%2==0&&
			mx*2<=s[i]-s[k-1])ans++;
		}
		if(i>130){
			od[s[j]&1]++;
			ans+=od[s[i]&1];
			j++;
		}
    }
    printf("%I64d",ans);
}