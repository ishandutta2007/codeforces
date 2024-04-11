#include<bits/stdc++.h>
using namespace std;
using nagai=long long;
#define sz(x) (int)(x.size())

const int N=5050;
int dp[N];
const int oo=0x3f3f3f3f;

int ha[N];
int pw[N];
const int mod=999239239;
const int P=228228239;

int su(int a,int b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
int mu(int a,int b){
	return (nagai)a*b%mod;
}
int di(int a,int b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}

int getha(int l,int r){
	int ans=di(ha[r],mu(ha[l],pw[r-l]));
	return ans;
}

struct hasher{
	unsigned int operator()(const pair<short,int>&a) const {
		return a.first*1488239228^a.second;
	}
};

int arr[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	dp[0]=0;
	fill(dp+1,dp+N,oo);
	pw[0]=1;
	for(int i=0;i<n;++i){
		pw[i+1]=mu(pw[i],P);
		ha[i+1]=su(mu(ha[i],P),s[i]);
	}
	for(int i=n-1;i>=0;--i){
		for(int j=i-1;j>=0;--j){
			if(s[i]==s[j]){
				if(i==j-1||j==n-1)
					arr[i][j]=1;
				else
					arr[i][j]=arr[i+1][j+1]+1;
			}
		}
	}
	for(int i=0;i<n;++i){
		dp[i+1]=min(dp[i+1],dp[i]+a);
		int len=0;
		for(int j=0;j<i;++j)
			len=max(len,min(arr[i][j],i-j));
		for(int j=i+1;j<=i+len;++j){
			dp[j]=min(dp[j],dp[i]+b);
		}
	}
	cout<<dp[n]<<'\n';
	return 0;

}