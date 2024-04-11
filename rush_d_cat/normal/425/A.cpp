#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int N=202;
int n,k,a[N],dp[N][20];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int k=i;k<=j;k++)sum+=a[k];
			multiset<int> s1,s2;
			for(int k=1;k<=n;k++){
				if(k<=j&&k>=i) s1.insert(a[k]);
				else s2.insert(a[k]);
			}
			for(int x=1;x<=k;x++){
				if(s1.size()&&s2.size()) {
					int A=*s1.begin();
					int B=*s2.rbegin();
					if(B>=A){
						sum+=B-A;
						s1.erase(s1.find(A));
						s2.erase(s2.find(B));
					}
				}
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
}