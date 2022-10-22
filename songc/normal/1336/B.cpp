#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, R, G, B;
LL X[101010], Y[101010], Z[101010];
LL ans;

int main(){
	scanf("%d", &TC);
	while(TC--){
		ans = INF;
		scanf("%d %d %d", &R, &G, &B);
		for (int i=1; i<=R; i++) scanf("%lld", &X[i]);
		for (int i=1; i<=G; i++) scanf("%lld", &Y[i]);
		for (int i=1; i<=B; i++) scanf("%lld", &Z[i]);
			sort(X+1, X+R+1);
			sort(Y+1, Y+G+1);
			sort(Z+1, Z+B+1);
		int r=1, g=1, b=1;
		for (r=1; r<=R; r++){
			while (g<G && Y[g+1] <= X[r]) g++;
			while (b<B && Z[b] < X[r]) b++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}

		r=1, g=1, b=1;
		for (r=1; r<=R; r++){
			while (b<B && Z[b+1] <= X[r]) b++;
			while (g<G && Y[g] < X[r]) g++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}

		r=1, g=1, b=1;
		for (g=1; g<=G; g++){
			while (r<R && X[r+1] <= Y[g]) r++;
			while (b<B && Z[b] < Y[g]) b++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}

		r=1, g=1, b=1;
		for (g=1; g<=G; g++){
			while (b<B && Z[b+1] <= Y[g]) b++;
			while (r<R && X[r] < Y[g]) r++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}

		r=1, g=1, b=1;
		for (b=1; b<=B; b++){
			while (g<G && Y[g+1] <= Z[b]) g++;
			while (r<R && X[r] < Z[b]) r++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}

		r=1, g=1, b=1;
		for (b=1; b<=B; b++){
			while (r<R && X[r+1] <= Z[b]) r++;
			while (g<G && Y[g] < X[r]) g++;
			ans = min(ans, (X[r]-Y[g])*(X[r]-Y[g])+(Z[b]-Y[g])*(Z[b]-Y[g])+(X[r]-Z[b])*(X[r]-Z[b]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}