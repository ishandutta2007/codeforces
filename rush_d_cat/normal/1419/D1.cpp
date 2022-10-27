#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
int n,a[N],p[N];
bool chk(int mid){
	vector<int> v; v.push_back(a[1]);
	for(int i=1;i<mid;i++){
		v.push_back(max(a[i],a[i+1]));
	}
	v.push_back(a[mid]);
	//printf("mid=%d\n", mid);
	//return 0;
	multiset<int> s;
	for(int i=mid+1;i<=n;i++){
		s.insert(a[i]);
	}
	bool ok=true;
	int pos=0;
	for(auto x:v){
		auto it=s.upper_bound(x);
		if(it==s.end()){
			ok=false; break;
		}
		p[pos++]=(*it);
		s.erase(s.find(*it));
	}
	return ok;
}
int main() {
	//while(1){
		scanf("%d",&n);
		//n=rand()%100000+1;
		for(int i=1;i<=n;i++){
			//a[i]=rand()%1000+1;
			scanf("%d",&a[i]);
		}

		sort(a+1,a+1+n);
		bool can=1; int cnt=0;
		for(int i=2;i<=n;i++)if(a[i]>a[1])++cnt;
		if(cnt<=1){
			printf("0\n");
			for(int i=1;i<=n;i++)printf("%d ", a[i]);
			printf("\n");
			//continue;
			return 0;
		}

		int l=1,r=(n-1)/2 + 1;
		//printf("l=%d,r=%d\n", l,r);
		while(r-l>1){
			int mid=(l+r)>>1;
			if(chk(mid)) l=mid; else r=mid;
		}
		chk(l);
		//printf("l = %d\n", l);
		printf("%d\n", l);
		multiset<int> values;
		for(int i=1;i<=n;i++)values.insert(a[i]);

		printf("%d ", p[0]); values.erase(values.find(p[0]));
		for(int i=1;i<=l;i++){
			printf("%d %d ", a[i], p[i]); values.erase(values.find(a[i])); values.erase(values.find(p[i]));
		}
		while(values.size()){
			printf("%d ", *values.begin());
			values.erase(values.begin());
		}
		
	//}
}