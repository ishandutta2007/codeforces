#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll arr[1010101];
ll brr[1010101];
ll dp[1010101];

string s1,s2,s3;

int main(){
	ll i,j,k,l,m,n,a,b,c,d;
	scanf("%lld",&n);
	while(n--){
		cin>>s1>>s2>>s3;
		ll m=s1.size();
		ll chk=1;
		for(i=0;i<m;i++){
			if(s2[i]!=s3[i]&&s1[i]!=s3[i]){
				chk=0;
				break;
			}
		}
		if(chk) printf("YES\n");
		else printf("NO\n");
	}
}