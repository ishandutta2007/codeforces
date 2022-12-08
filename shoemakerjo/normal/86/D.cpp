#include <bits/stdc++.h>

int i,l,r,n,m,D,c[200005],f[1000005];
long long cnt,ans[200005];
struct Q{
	int l,r,k;
	bool operator<(const Q&a)const{
		return (l-1)/D<(a.l-1)/D||(l-1)/D==(a.l-1)/D&&r<a.r;
	}
}a[200005];
int main()
{
    //freopen("powsub.inp","r",stdin);
    //freopen("powsub.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=m;a[i].k=i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	D=sqrt(n),std::sort(a+1,a+m+1);
	for(l=i=1;i<=m;ans[a[i++].k]=cnt)
	{
		for(;l<a[i].l;cnt-=1ll*c[l]*(2*--f[c[l++]]+1));
		for(;l>a[i].l;cnt+=1ll*c[--l]*(2*f[c[l]]+++1));
		for(;r<a[i].r;cnt+=1ll*c[++r]*(2*f[c[r]]+++1));
		for(;r>a[i].r;cnt-=1ll*c[r]*(2*--f[c[r--]]+1));
	}
	for(i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
}
// #include <bits/stdc++.h>
// #define ll long long
// #define pii pair<int, int>
// using namespace std;

// ll ans = 0LL;
// ll ins[1000001];

// ll temp;
// void add(int u) {
// 	ins[u]++;
// 	temp = ins[u];
// 	ans += (temp*temp - (temp-1)*(temp-1))*u;
// }
// void sub(int u) {
// 	ins[u]--;
// 	temp = ins[u];
// 	ans += (temp*temp - (temp+1)*(temp+1))*u;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(NULL);
// 	int n, m;
// 	// cin >> n >> m;
// 	scanf("%d%d", &n, &m);
// 	int nums[n];
// 	for (int i = 0; i <= 1000000; i++) {
// 		ins[i] = 0;
// 	}
// 	for (int i = 0; i < n; i++) {
// 		scanf("%d", &nums[i+1]);
// 		// cin >> nums[i+1];
// 	}
// 	int l, r;
// 	tuple<int, int, int, int> qus[m];
// 	for (int i = 0; i < m; i++) {
// 		// cin >> l >> r;
// 		scanf("%d%d", &l, &r);
// 		int bucket = l/sqrt(n);
// 		qus[i] = make_tuple(bucket, r, l, i);
// 	}
// 	sort(qus, qus+m);
// 	ll anses[m];
// 	int la, ra;
// 	for (int i = 0; i < m; i++) {
// 		r = get<1>(qus[i]);
// 		l = get<2>(qus[i]);
// 		int index = get<3>(qus[i]);
// 		// cout << r << " " << l << " " << index << endl;
// 		if (i == 0) {
// 			for (int j = l; j <= r; j++) {
// 				add(nums[j]);
// 			}
// 			anses[index] = ans;
// 			la = l;
// 			ra = r;
// 			// cout << ans << endl;
// 			continue;
// 		}
// 		while (la > l) {
// 			add(nums[la-1]);
// 			la--;
// 		}
// 		while (la < l) {
// 			sub(nums[la]);
// 			la++;
// 		}
// 		while (ra > r) {
// 			sub(nums[ra]);
// 			ra--;
// 		}
// 		while (ra < r) {
// 			add(nums[ra+1]);
// 			ra++;
// 		}
// 		anses[index] = ans;
// 		// cout << ans << endl;
// 	}
// 	for (int i = 0; i < m; i++) {
// 		cout << anses[i] << "\n";
// 	}
// 	// cin >> ans;
// }