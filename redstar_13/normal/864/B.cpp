#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
char a[220];
int f[200];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;scanf("%d",&n);
	cin>>a+1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>='a' and a[i]<='z'){
			int t=0;
			int j;
			for(j=i;j<=n;j++){
				if(a[j]>='a' and a[j]<='z') f[(int)a[j]]++;
				else break;
			}
			for(int k='a';k<='z';k++) if(f[k]) f[k]=0,t++;
			ans=max(ans,t);
			i=j-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}