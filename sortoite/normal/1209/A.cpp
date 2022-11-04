#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<int,int> pii;
typedef vector<int> VI;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int n;
	static int a[111];
	static int vst[111];
	
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i], vst[i]=0;
	
	sort(a, a+n);
	
	int ans=0;
	for(int i=0; i<n; i++) if(!vst[i]){
		for(int j=i; j<n; j++) if(a[j]%a[i]==0) vst[j]=1;
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}