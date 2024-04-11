#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define Mod 1000000007
int f[Maxn+5];
int a[Maxn+5];
vector<int> p[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				p[i].push_back(j);
				if(j*j!=a[i]){
					p[i].push_back(a[i]/j);
				}
			}
		}
		sort(p[i].begin(),p[i].end());
		for(int j=p[i].size()-1;j>=0;j--){
			if(p[i][j]>n){
				continue;
			}
			f[p[i][j]]+=f[p[i][j]-1];
			f[p[i][j]]%=Mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i];
		ans%=Mod;
	}
	printf("%d\n",ans);
	return 0;
}