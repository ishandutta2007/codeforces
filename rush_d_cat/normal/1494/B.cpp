#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t --) {
		int n,f[4]={0};
		cin >> n;
		for(int i=0;i<4;i++) cin>>f[i];

		pair<int,int> p[4];
		p[0]=make_pair(0,3);
		p[1]=make_pair(2,3);
		p[2]=make_pair(1,2);
		p[3]=make_pair(0,1);
		bool ok=false;
		for(int i=0;i<16;i++){
			int g[4]={0};
			for(int j=0;j<4;j++) g[j]=f[j];
			for(int j=0;j<4;j++) if(i>>j&1) {
				g[p[j].first] --; g[p[j].second] --;
			}
			bool can=true;
			for(int j=0;j<4;j++) if(!(g[j]>=0&&g[j]<=n-2)) can=false;
			if(can) ok=true;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}