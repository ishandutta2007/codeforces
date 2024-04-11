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
#include <stack>
#include <string>
#include <vector>
using namespace std;

int n;
int a[705];
bool dp[705][705][2];
int gcd[705][705];

int GCD(int a,int b){
	return !b?a:GCD(b,a%b);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			gcd[i][j]=gcd[j][i]=GCD(a[i],a[j]);
		}
	}
	for(int i=1;i<=n+1;i++){
		dp[i][i-1][0]=dp[i][i-1][1]=1;
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			//dp[i][j][0]
			for(int k=i;k<=j;k++){
				if(gcd[k][j+1]!=1){
					dp[i][j][0]|=(dp[i][k-1][0]&dp[k+1][j][1]);
				}
			}
			//dp[i][j][1]
			for(int k=i;k<=j;k++){
				if(gcd[k][i-1]!=1){
					dp[i][j][1]|=(dp[i][k-1][0]&dp[k+1][j][1]);
				}
			}
		}
	}
	puts(dp[1][n][0]?"Yes":"No");
	return 0;
}