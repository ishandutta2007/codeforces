#include <bits/stdc++.h>
using namespace std;

int n,q,dp[5005],dp2[5005][5005];
vector<short> ss[5005];
int cnt[5005];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			ss[j].push_back(i+1);
			cnt[j]++;
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			ans--;
		}else if(cnt[i]==1){
			dp[ss[i][0]]++;
		}else if(cnt[i]==2){
			dp2[ss[i][0]][ss[i][1]]++;
		}
	}
	int res=0;
	for(int i=1;i<=q;i++){
		for(int j=i+1;j<=q;j++){
			res=max(res,ans-dp[i]-dp[j]-dp2[i][j]);
		}
	}
	cout<<res<<endl;
	return 0;
}