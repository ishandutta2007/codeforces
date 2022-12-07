#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int dp[205][55][55][2];
int n,len,inf=10000;string s;
int cal(int t,int m,int k,int d){
	if(m==k) return t;
	if(t>=len) return inf;
	if(dp[t][m][k][d]>-1) return dp[t][m][k][d];
	int nk=k,nd=d,i,ret=0;
	if(d<1){nk++;if(nk==n-1) nd=1;}
	else{nk--;if(nk<1) nd=0;}
//	if(s[t]=='0' && nk==m) return t+1;
	if(s[t]=='0'){
		for(i=m-1;i<m+2;i++){
			if(i<0 || i>=n) continue;
			if(i==nk || i==k) ret=max(ret,t+1);
			else ret=max(ret,cal(t+1,i,nk,nd));
		}
	}
	else{
		for(i=0;i<n;i++){
			if(i==nk) ret=max(ret,t+1);
			else ret=max(ret,cal(t+1,i,nk,nd));
		}
	}
//	cout<<t<<' '<<m<<' '<<k<<' '<<d<<' '<<ret<<endl;
	return dp[t][m][k][d]=ret;
}
int main()
{
	int m,k,i,j,l,out;string f,g;
	for(i=0;i<205;i++) for(j=0;j<55;j++) for(l=0;l<55;l++) dp[i][j][l][0]=dp[i][j][l][1]=-1;
	cin>>n>>m>>k;cin>>f>>g;cin>>s;len=s.size();//cout<<f<<endl;
	if(g=="tail") out=cal(0,m-1,k-1,0);else out=cal(0,m-1,k-1,1);
	if(out>=inf) cout<<"Stowaway"<<endl;else cout<<"Controller "<<out<<endl;
	return 0;
}