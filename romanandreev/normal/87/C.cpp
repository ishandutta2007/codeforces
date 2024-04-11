#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
ll b[1000000];
int dp[1000000];
int dp1[1000000];
int g[1000000];

vector<pi> v[1000000];
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
	cin>>n;
	for (ll i=0;i<=2*n;i++){
		b[i]=i*(i+1)/2;
	}
	for (int i=0;i<=2*n;i++){
		for (int j=i-2;j>=0;j--){
			if (b[i]-b[j]<=n){
				v[b[i]-b[j]].pb(mp(j,i));
			} else break;
		}
	}
	dp[1]=0;
	int ff;
	int cnt=0;
	for (int i=2;i<=n;i++){
		cnt++;
		for (int j=0;j<(int)v[i].size();j++){
			ff=dp1[v[i][j].sc]^dp1[v[i][j].fs];			
			g[ff]=cnt;
		}
		for (int j=0;;j++){
			if (g[j]!=cnt){
				dp[i]=j;
				dp1[i]=dp[i]^dp1[i-1];
				break;
			}
		}
	}
	int ans;
	if (dp[n]==0){
		printf("-1\n");
	} else {
		ans=n;
		for (int j=0;j<(int)v[n].size();j++){
			ff=dp1[v[n][j].sc]^dp1[v[n][j].fs];			
			if (ff==0){
				ans=min(ans,v[n][j].sc-v[n][j].fs);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}