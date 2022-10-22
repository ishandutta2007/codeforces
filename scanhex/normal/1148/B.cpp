#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())


const int N=200200;
const int oo=2000000200;
int a[N];
int b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<m;++i)
		cin>>b[i];
	nagai L=0,R=oo;
	while(R-L>1){
		nagai M=(L+R)/2;
		int cntb=upper_bound(b,b+m,M-tb)-b;
		if(cntb<=k){
			L=M;
			continue;
		}
		bool g=false;
		for(int i=0;i<cntb;++i){
			int rest=k-(cntb-i-1);
			if(rest<0)continue;
			if(rest>=n||a[rest]+ta>b[i]){
				g=true;
			}
		}
		if(g)
			L=M;
		else
			R=M;
	}
	if(R==oo)
		cout<<-1<<'\n';
	else
		cout<<R<<'\n';
	return 0;
}