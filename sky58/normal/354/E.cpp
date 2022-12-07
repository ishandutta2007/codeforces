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
#define N 5
bool dp[25][N+2];
int p1[25][N+2],p2[25][N+2];
int sum[30];
int tmp[30][8];
lint ret[8];
int main()
{
	int t,n=0,m;lint a;string s;
	rep(i,7) rep(j,7){
		if(i+j>6) continue;
		rep(k,i) tmp[n][k]=4;
		rep(k,j) tmp[n][i+k]=7;
		rep(k,6-i-j) tmp[n][i+j+k]=0;
		sum[n]=4*i+7*j;n++;
		//cout<<n<<' '<<sum[n-1]<<endl;
	}
	cin>>t;
	rep(i,t){
		cin>>s;istringstream sin(s);sin>>a;
		m=s.size();
		memset(dp,false,sizeof(dp));dp[0][0]=true;
		rep(j,m){
			int b=(int)(a%10);
			rep(k,N){
				if(!dp[j][k]) continue;
				//cout<<j<<' '<<k<<endl;
				rep(l,n){
					if(b==(sum[l]+k)%10){
						int ne=(sum[l]+k)/10;
						dp[j+1][ne]=true;p1[j+1][ne]=k;p2[j+1][ne]=l;
					}
				}
			}
			a/=10;
		}
		if(!dp[m][0]){
			cout<<-1<<endl;continue;
		}
		memset(ret,0,sizeof(ret));
		int now=0;
		for(int j=m;j>0;j--){
			int ne=p2[j][now];
			rep(k,6) ret[k]=ret[k]*10+tmp[ne][k];
			now=p1[j][now];
		}
		rep(j,6){
			cout<<ret[j];if(j<5) cout<<' ';else cout<<endl;
		}
	}
}