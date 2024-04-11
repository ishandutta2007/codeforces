#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[210][2][210][514];
int sen[210][22],po[210][22];
//pint s2[210][210][22];int p2[210][210][22];
int val[210],len[210],sum[210];
vector<int> pat[210];
int N,M,K;lint mo=1000000007;
lint cal(vector<int> a){
	int n=a.size();lint ret=0;
	//rep(i,n) cout<<a[i]<<' ';cout<<endl;
	memset(dp,0,sizeof(dp));
	dp[0][0][sum[N]+1][0]=1;
	rep(i,n) rep(j,sum[N]+2) rep(k,K+1){
		if(dp[i][0][j][k]+dp[i][1][j][k]<1) continue;
		dp[i][0][j][k]%=mo;dp[i][1][j][k]%=mo;
		//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][0][j][k]<<' '<<dp[i][1][j][k]<<endl;
		rep(l,M){
			int ns=sen[j][l],np=min(K,po[j][l]+k);
			if(l<a[i]) dp[i+1][1][ns][np]+=dp[i][0][j][k]+dp[i][1][j][k];
			else dp[i+1][1][ns][np]+=dp[i][1][j][k];
			if(l==a[i]) dp[i+1][0][ns][np]+=dp[i][0][j][k];
		}
	}
	rep(i,sum[N]+2) rep(j,K){
		ret=(ret+dp[n][0][i][j]+dp[n][1][i][j])%mo;
	}
	//cout<<ret<<endl;
	return ret;
}
int ca2(vector<int> a){
	int n=a.size(),p=0,s=sum[N]+1;
	rep(i,n){
		int ns=sen[s][a[i]],np=p+po[s][a[i]];
		s=ns;p=np;
	}
	if(p<K) return 1;return 0;
}
int main()
{
	vector<int> lo,hi;
	cin>>N>>M>>K;int x,y;K++;
	cin>>x;rep(i,x){cin>>y;lo.pb(y);}
	cin>>x;rep(i,x){cin>>y;hi.pb(y);}
	rep(i,N){
		cin>>len[i];sum[i+1]=sum[i]+len[i];
		rep(j,len[i]){
			cin>>x;pat[i].pb(x);
		}
		cin>>val[i];
	}
	rep(i,210) rep(j,22) sen[i][j]=sum[N];
	rep(i,N) REP(j,1,len[i]+1) rep(k,M){
		REP(l,1,j+2) rep(m,N){
			if(len[m]<l) continue;
			if(pat[m][l-1]!=k) continue;
			int f=0;
			rep(n,l-1){
				if(pat[m][n]!=pat[i][j-(l-1)+n]){f=1;break;}
			}
			if(f<1){
				//s2[i][j][k]=mp(l,m);if(len[m]==l) p2[i][j][k]+=val[m];
				sen[sum[i]+j-1][k]=sum[m]+l-1;if(len[m]==l) po[sum[i]+j-1][k]+=val[m];
			}
		}
	}
	rep(i,N) rep(j,M){
		if(pat[i][0]==j){
			sen[sum[N]][j]=sum[i];if(len[i]==1) po[sum[N]][j]+=val[i];
			if(j>0){sen[sum[N]+1][j]=sum[i];if(len[i]==1) po[sum[N]+1][j]+=val[i];}
		}
	}
	sen[sum[N]+1][0]=sum[N]+1;
	rep(i,sum[N]+2){
		//rep(j,M) cout<<sen[i][j]<<','<<po[i][j]<<' ';cout<<endl;
	}
	cout<<(mo+cal(hi)-cal(lo)+ca2(lo))%mo<<endl;
}