#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 10;
typedef long long LL;
int n;
int vis[N],res[N],a[N];
int main() {
	cin>>n;
	int ans=0;
	for(int i=0;i<N;i++)a[i]=1e9;
	for(int i=n;i>=2;i--){
		++ans;
		for(int j=i+i;j<=n;j+=i){
			if(vis[j]==0){
				vis[j]=1; ans--;
			}
		}
		res[i-1]=ans+i-1;
	}
	int pre=1;
	for(int i=1;i<n;i++){
		for(int j=pre;j<=res[i];j++) a[j]=i; 
		pre=res[i]+1;
	}
	for(int i=2;i<=n;i++)printf("%d ", a[i]);
}