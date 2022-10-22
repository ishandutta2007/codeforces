#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	int L=-1,R=m;
	while(R-L>1){
		 int M=(L+R)/2;
		 int cur=0;
		 bool bad=0;
		 for(int i=0;i<n;++i){
			 if(a[i]+M-m>=cur)
				 ;
			 else if(a[i]+M<cur)
				 bad=true;
			 else
				 cur=max(cur,a[i]);
		 }
		 if(bad)
			 L=M;
		 else
			 R=M;
	}
	cout<<R<<'\n';
	return 0;
}