#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

deque<ll> dq;
string s;
string s2;
int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,ch=0,now=1000000,mini=1000000,maxi=1000000;
		cin>>s>>s2;
		ll n=s.size();
		ll m=s2.size();
		vector<ll> v[30];
		for(i=0;i<=28;i++)
			v[i].clear();
		for(i=0;i<n;i++){
			v[s[i]-'a'].push_back(i);
		}

		ll ans=1;
		ll fl=-100;

		for(i=0;i<m;i++){
			k=s2[i]-'a';
			if(v[k].empty()){
				printf("-1\n");
				ch=1;
				break;
			}
			ll idx=lower_bound(v[k].begin(), v[k].end(),fl)-v[k].begin();
			fl=v[k][idx]+1;
			if(idx>=v[k].size()){
				ans++;
				fl=v[k][0]+1;
			}

			//printf("%lld %lld %lld %lld\n",t,i,fl,idx);
			

		}
		if(ch==0) printf("%lld\n",ans);

	}
	
}