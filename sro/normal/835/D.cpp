#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define INT long long
using namespace std;
//Coded by Charlieyan, all rights reserved.
//Orz DJQ in order to AC

INT Ha=97;
INT mii[5005];
int dp[5005][5005];
int n;
char s[5005];
INT qzhaa[5005];
int cnt[5005];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	mii[0]=1;
	for(int i=1;i<=n;i++){
		mii[i]=mii[i-1]*Ha;
	}
	for(int i=1;i<=n;i++){
		qzhaa[i]=qzhaa[i-1]*Ha+s[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		INT haa=0,haa2=0;
		for(int j=i;j<=n;j++){
			haa=haa*Ha+s[j];
			haa2+=mii[j-i]*s[j];
			if(haa==haa2){
				dp[i][j]=1;
			}else{
				dp[i][j]=0;
			}
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int k1=i+len/2-1,k2=j-len/2+1;
			//cerr<<i<<' '<<k1<<' '<<k1-i+1<<' '<<k2<<' '<<j<<' '<<qzhaa[k1]-qzhaa[i-1]*mii[k1-i+1]<<' '<<qzhaa[j]-qzhaa[k2-1]*mii[j-k2+1]<<endl;
			if(qzhaa[k1]-qzhaa[i-1]*mii[k1-i+1]==qzhaa[j]-qzhaa[k2-1]*mii[j-k2+1]&&dp[i][k1]){
				dp[i][j]=max(dp[i][j],dp[i][k1]+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=dp[i][j];k++){
				cnt[k]++; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",cnt[i],i==n?'\n':' ');
	}
	return 0;
}