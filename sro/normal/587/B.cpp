#include <bits/stdc++.h>
using namespace std;

int n,k;
long long l;
int a[1000005];
int f[1000005];
vector<vector<int> > dp;
const int jt=1000000007;

bool y1isafunctionmadebyacocksucker(int x,int y){
	return a[x]<a[y];
}

int main(){
	scanf("%d%lld%d",&n,&l,&k);
	dp=vector<vector<int> >(k,vector<int>(n,0));
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		f[i]=i;
		dp[0][i]=1;
	}
	sort(f,f+n,y1isafunctionmadebyacocksucker);
	for(int i=1;i<k;i++){
		int sum=0;
		int r=0;
		for(int j=0;j<n;j++){
			while(r<n&&a[f[r]]<=a[f[j]]){
				sum+=dp[i-1][f[r]];
				if(sum>=jt){
					sum-=jt;
				}
				r++;
			}
			dp[i][f[j]]=sum;
		}
	}
	int lim=l%n;
	long long grp=l/n;
	int ans=0;
	for(int i=0;i<k;i++){
		if(grp-i+1<=0){
			break;
		}
		for(int j=0;j<lim;j++){
			ans=(ans+(dp[i][j]*((grp-i+1)%jt))%jt)%jt;
		}
	}
	for(int i=0;i<k;i++){
		if(grp-i+1<=0){
			break;
		}
		for(int j=lim;j<n;j++){
			ans=(ans+(dp[i][j]*((grp-i)%jt))%jt)%jt;
		}
	}
	printf("%d\n",ans);
	return 0;
}