#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=50000+10;
int t, n;
pair<int,int> a[N];
int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].first);a[i].second=i;
		}
		sort(a+1,a+1+n);
		if(a[1].first+a[2].first<=a[n].first){
			vector<int> v;
			v.push_back(a[1].second);
			v.push_back(a[2].second);
			v.push_back(a[n].second);
			sort(v.begin(), v.end());
			printf("%d %d %d\n", v[0],v[1],v[2]);
		} else printf("%d\n", -1);
	}
}