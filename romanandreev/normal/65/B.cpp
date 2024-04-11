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
int dp[1010][2020];
int bc[1010][2020];
vector<int> v[1010];
void bct(int n,int k){
	if (n>0){
		bct(n-1,bc[n][k]);
	}
	printf("%4d\n",k);
}
int a[1010];
int b[1010];
int c[1010];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,cnt;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[0]=a[i]%10;
		c[1]=(a[i]/10)%10;
		c[2]=(a[i]/100)%10;
		c[3]=(a[i]/1000)%10;
		for (int j=1000;j<=2011;j++){
			b[0]=j%10;
			b[1]=(j/10)%10;
			b[2]=(j/100)%10;
			b[3]=(j/1000)%10;
			cnt=0;
			for (int k=0;k<4;k++)
				if (b[k]!=c[k]) cnt++;
			if (cnt<=1){
				//cerr<<a[i]<<" "<<j<<endl;
				v[i].pb(j);
			}
		}
	}
	for (int i=0;i<(int)v[0].size();i++)
		dp[0][v[0][i]]=1;
	for (int i=1;i<n;i++){
		for (int j=1000;j<=2011;j++)
			if (dp[i-1][j]==1){
				for (int k=0;k<(int)v[i].size();k++){
					if (v[i][k]>=j){
						dp[i][v[i][k]]=1;
						bc[i][v[i][k]]=j;
					}
				}
			}
	}
	for (int j=1000;j<=2011;j++){
		if (dp[n-1][j]==1){
			bct(n-1,j);
			return 0;
		}
	}
	cout<<"No solution"<<endl;
    return 0;
}