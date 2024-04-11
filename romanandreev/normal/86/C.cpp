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
string ss,s;
const int md=((int)1e9)+9;
int n,kv,m,ans;
int b[1000][250];
int sf[1000];
int pr[1000];
int fl[1000];
int len[1000];
int lenn[1000];

int dp[2000][20][200];
char prc[1000];

void add(string s){
	int tk=1;
	for (int i=0;i<(int)s.length();i++){
		if (b[tk][s[i]]==0){
			b[tk][s[i]]=++kv;
			pr[kv]=tk;
			len[kv]=len[tk]+1;
			prc[kv]=s[i];
		}
		tk=b[tk][s[i]];
	}
	fl[tk]=1;
	lenn[tk]=len[tk];
}
void calcsf(int v){
	if (sf[v]!=-1) return;
	if (pr[v]==1) sf[v]=1; else {
		calcsf(pr[v]);
		int tk=sf[pr[v]];
		while (tk!=1 && b[tk][prc[v]]==0){
			calcsf(tk);
			tk=sf[tk];
		}
		if (b[tk][prc[v]]!=0)
			sf[v]=b[tk][prc[v]];
		else 
			sf[v]=1;
	}
	calcsf(sf[v]);
	if (fl[sf[v]]==1){
		fl[v]=1;
		lenn[v]=max(lenn[v],lenn[sf[v]]);
	}
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	scanf("%d%d",&n,&m);
	kv=1;
	for (int i=0;i<m;i++){
		cin>>s;
		add(s);
	}
	for (int i=1;i<=kv;i++){
		sf[i]=-1;
	} 
	sf[1]=1;
	len[1]=0;
	for (int i=2;i<=kv;i++)
		calcsf(i);
	ss="ACGT";
	for (int i=2;i<=kv;i++)
		for (int j=0;j<4;j++){
			int tk=i;
			while (tk!=1 && b[tk][ss[j]]==0){
				tk=sf[tk];
			}
			if (b[tk][ss[j]]!=0){
				b[i][ss[j]]=b[tk][ss[j]];
			}
		}
	/*for (int i=1;i<=kv;i++){
		cerr<<i<<" "<<sf[i]<<" "<<fl[i]<<endl;
		for (int j=0;j<4;j++)
			cerr<<b[i][ss[j]]<<endl;
	}
	cerr<<endl;*/
	dp[0][0][1]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=10;j++){
			for (int k=1;k<=kv;k++)if (dp[i][j][k]!=0){
				//cerr<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				for (int l=0;l<4;l++) if (b[k][ss[l]]!=0){
					int hh=j+1;
					if (fl[b[k][ss[l]]]==1 && lenn[b[k][ss[l]]]>=hh){
						hh=0;
					}
					dp[i+1][hh][b[k][ss[l]]]=(dp[i+1][hh][b[k][ss[l]]]+dp[i][j][k])%md;
				}
			}
	}
	/*dp[0][1]=1;
	for (int i=0;i<n;i++){
			for (int k=1;k<=kv;k++)if (dp[i][k]!=0){
				for (int l=0;l<4;l++) if (b[k][ss[l]]!=0){
					dp[i+1][b[k][ss[l]]]=(dp[i+1][b[k][ss[l]]]+dp[i][k])%md;
				}
			}
	}*/

	ans=0;
	for (int i=1;i<=kv;i++) if (fl[i]==1){
		ans=(ans+dp[n][0][i])%md;
	}
	cout<<ans<<endl;
	return 0;
}