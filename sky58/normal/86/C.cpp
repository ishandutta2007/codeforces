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
int ed1[12][12][5],ed2[12][12][5],aru[12][12][5];
int dp[1100][12][12][12];
string s[12];
string ge="ATGC";
int main()
{
	memset(aru,0,sizeof(aru));memset(dp,0,sizeof(dp));dp[0][0][0][0]=1;
	int i,j,k,l,m,L,n,out=0,mo=1000000009;
	cin>>L>>n;
	for(i=0;i<n;i++) cin>>s[i];
	for(i=0;i<n;i++) for(j=0;j<=s[i].size();j++) for(k=0;k<4;k++){
		string t=s[i].substr(0,j)+ge[k];int a=0,b=0;
		for(l=0;l<n;l++){
			int le=s[l].size();
			for(m=min(le,j+1);m>0;m--){
				if(s[l].substr(0,m)==t.substr(j+1-m)) break;
			}
			if(b<m){a=l;b=m;}
			if(le<=j+1) if(s[l]==t.substr(j+1-le)) aru[i][j][k]=max(aru[i][j][k],le);
		}
		ed1[i][j][k]=a;ed2[i][j][k]=b;
	}
	for(i=0;i<L;i++) for(j=0;j<10;j++) for(k=0;k<n;k++) for(l=0;l<=s[k].size();l++){
		if(dp[i][j][k][l]<1) continue;
		for(m=0;m<4;m++){
//			cout<<aru[k][l][m]<<' '<<ed1[k][l][m]<<' '<<ed2[k][l][m]<<endl;
			if(aru[k][l][m]>j){
				dp[i+1][0][ed1[k][l][m]][ed2[k][l][m]]+=dp[i][j][k][l];
				dp[i+1][0][ed1[k][l][m]][ed2[k][l][m]]%=mo;
			}
			else if(ed2[k][l][m]>j){
				dp[i+1][j+1][ed1[k][l][m]][ed2[k][l][m]]+=dp[i][j][k][l];
				dp[i+1][j+1][ed1[k][l][m]][ed2[k][l][m]]%=mo;
			}
		}
	}
	for(k=0;k<n;k++) for(l=0;l<=s[k].size();l++){
		out=(out+dp[L][0][k][l])%mo;
	}
	cout<<out<<endl;
	return 0;
}