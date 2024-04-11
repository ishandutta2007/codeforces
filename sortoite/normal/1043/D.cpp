#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

#define NN 100100
int fa[NN], vst[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	map <pii, int> mp;
	for(int i=0; i<m; i++){
		for(int j=0, a, b; j<n; j++){
			scanf("%d", &b);
			if(j) mp[pii(a, b)]++;
			a=b;
		}
	}
	
	for(auto p : mp){
		if(p.y==m) fa[p.x.x]=p.x.y, vst[p.x.y]=1;
	}
	
	INT ans=0;
	for(int i=1; i<=n; i++) if(!vst[i]){
		int k=1, u=i;
		while(fa[u]) k++, u=fa[u];
		ans+=(INT)k*(k+1)/2;
	}
	
	cout << ans << endl;
	
	return 0;
}