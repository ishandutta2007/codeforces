#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000+10;
int t,n,a[N],c[1000000+10];
vector<int> del;
bool test(int x) {
	int cur=2*n,sum=x;
	del.clear();

	for(int i=1;i<=n;i++){
		while(cur>=1 && c[a[cur]] == 0) --cur;
		if(cur==0) {
			for(auto x:del) c[x]++;
			return false;
		}

		c[a[cur]] --; del.push_back(a[cur]);
		int need=sum-a[cur];
		if(c[need]==0) {
			for(auto x:del) c[x]++;
			return false;			
		}
		//printf("%d %d\n", a[cur],need);
		c[need]--; del.push_back(need);
		sum=a[cur];
	}
	//printf("#\n");
	return true;
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=2*n;i++) c[a[i]] ++;

		sort(a+1,a+1+2*n);
		//test(6); return 0;
		bool ok=0;
		for(int pos=1;pos<2*n;pos++){
			int x=a[2*n]+a[pos];
			if(test(x)){
				ok=1;
				printf("YES\n");
				printf("%d\n", x);
				for(int i=0;i+1<del.size();i+=2) {
					printf("%d %d\n", del[i],del[i+1]);
				} 
				break;
			}
		}
		if(!ok) {
			printf("NO\n");
		}
		for(int i=1;i<=2*n;i++) c[a[i]]=0;
	}
}