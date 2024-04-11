#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, A[404040], ans;
vector<int> X, Y;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]);
	for (int k=0; k<=25; k++){
		X.clear(), Y.clear();
		for (int j=1; j<=N; j++){
			if (A[j]&(1<<k)) X.pb(A[j]&((1<<k)-1));
			else Y.pb(A[j]&((1<<k)-1));
		}
		sort(all(X)), sort(all(Y));
		LL cnt=0;
		int t=(int)Y.size()-1;
		for (int x : X){
			while (t>=0 && Y[t]+x >= (1<<k)) t--;
			cnt+=t+1;
		}
		t=(int)X.size();
		for (int j=0; j<(int)X.size()-1; j++){
			while (t>0 && X[t-1]+X[j] >= (1<<k)) t--;
			cnt+=X.size()-max(t, j+1);
		}
		t=(int)Y.size();
		for (int j=0; j<(int)Y.size()-1; j++){
			while (t>0 && Y[t-1]+Y[j] >= (1<<k)) t--;
			cnt+=Y.size()-max(t, j+1);
		}
		if (cnt&1) ans += (1<<k);
	}
	printf("%d\n", ans);
	return 0;
}