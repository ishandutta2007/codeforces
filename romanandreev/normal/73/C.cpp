#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
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
char s[10000];
int n,k,N,z;
char x,y;
int c[1000][1000];
int dp[200][200][200];
const int inf=(int)(1e9);
int main(){
  //  freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%s%d",s,&k);
    scanf("%d\n",&n);
    int N=strlen(s);
    for (int i=0;i<n;i++){
    	scanf("%c %c %d\n",&x,&y,&z);
    	c[x][y]=z;
    }
    for (int i=0;i<=N;i++)
    	for (int j=0;j<=k;j++)
    		for (int l='a';l<='z';l++)
    			dp[i][j][l]=-inf;
    dp[0][0][s[0]]=0;
    for (int i='a';i<='z';i++){
    	dp[0][1][i]=0;
    }
    for (int i=1;i<N;i++){
    	for (int kk=0;kk<=k;kk++)
    		for (int j='a';j<='z';j++) if (dp[i-1][kk][j]!=-inf){
//    			cerr<<i<<" "<<kk<<" "<<(char)j<<" "<<dp[i-1][kk][j]<<endl;
    			dp[i][kk][s[i]]=max(dp[i][kk][s[i]],dp[i-1][kk][j]+c[j][s[i]]);
    			for (int jj='a';jj<='z';jj++)
	    			dp[i][kk+1][jj]=max(dp[i][kk+1][jj],dp[i-1][kk][j]+c[j][jj]);
	    	}
    }
    int ans=-inf;
    for (int i=0;i<=k;i++)
    	for (int j='a';j<='z';j++)
    		ans=max(ans,dp[N-1][i][j]);
	cout<<ans;
    return 0;
}