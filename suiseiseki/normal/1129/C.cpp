/*#include <cstdio>
#include <cstring>
#define Mod 1000000007
#define ll long long
#define Maxn 3000
#define Hash_1 100000007
#define Hash_2 100000037
#define Hash_3 20000003
#define eps_1 3
#define eps_2 5
#define eps_3 7
bool have[105];
int a[Maxn+5];
int f[Maxn+5][Maxn+5];
bool has_1[Hash_1+5];
bool has_2[Hash_2+5];
bool has_3[Hash_3+5];
bool check_prime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	memset(have,1,sizeof have);
	have[76]=0;
	have[70]=0;
	have[53]=0;
	have[80]=0;
	int n;
	scanf("%d",&n);
	int sum=0;
	int tmp_1,tmp_2,tmp_3;
	int wat;
	f[0][1]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
		tmp_1=tmp_2=tmp_3=0;
		f[i][i+1]=1;
		for(int j=i;j>0;j--){
			tmp_1=tmp_1*eps_1+a[j];
			tmp_1%=Hash_1;
			tmp_2=tmp_2*eps_2+a[j];
			tmp_2%=Hash_2;
			tmp_3=tmp_3*eps_3+a[j];
			tmp_3%=Hash_3;
			wat=0;
			for(int k=1;k<=4&&k<=i-j+1;k++){
				wat=wat*3+a[i-k+1];
				if(!have[wat]){
					continue;
				}
				f[i][j]+=f[i-k][j];
				f[i][j]%=Mod;
			}
			if(!has_1[tmp_1]||!has_2[tmp_2]||!has_3[tmp_3]){
				sum+=f[i][j];
			}
			sum%=Mod;
			has_1[tmp_1]=1;
			has_2[tmp_2]=1;
			has_3[tmp_3]=1;
		}
		printf("%d\n",sum);
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3, mxS=mxN*(mxN+1)/2+1, M=1e9+7;
int n, a[mxN], c[mxS][2], p[mxS], dp[mxS], ans, m=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[0]=1;
	p[0]=-1;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=i, u=0; ~j; u=c[u][a[j--]]) {
			if(c[u][a[j]])
				continue;
			for(int k=0, v=u, b=0; k<4&&~v; ++k, v=p[v]) {
				b=b<<1|a[j+k];
				if(k<3||b^3&&b^5&&b<14)
					dp[m]=(dp[m]+dp[v])%M;
			}
			ans=(ans+dp[m])%M;
			p[m]=u;
			c[u][a[j]]=m++;
		}
		cout << ans << "\n";
	}
}