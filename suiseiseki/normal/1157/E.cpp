#include <cstdio>
#include <set>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
multiset<int> b;
int c[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		b.insert(x);
	}
	multiset<int>::iterator it;
	for(int i=1;i<=n;i++){
		it=b.lower_bound(n-a[i]);
		if(it==b.end()){
			it=b.begin();
		}
		c[i]=a[i]+(*it);
		c[i]%=n;
		b.erase(it);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",c[i]);
	}
	puts("");
	return 0;
}