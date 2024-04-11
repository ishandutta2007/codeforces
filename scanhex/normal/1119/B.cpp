#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
int n;
nagai h;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	vector<nagai>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	int L=0,R=n+1;
	while(R-L>1){
		 int M=(L+R)/2;
		 auto a1=a;
		 sort(a.begin(),a.begin()+M);
		 reverse(a.begin(),a.begin()+M);
		 nagai h1=0;
		 for(int i=0;i<M;i+=2){
			 h1+=a[i];
		 }
		 a=a1;
		 if(h1<=h)
			 L=M;
		 else
			 R=M;
	}
	cout<<L<<'\n';
	return 0;
}