#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<int> v1,v2,v3;int s1=0,s2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<0){
				v1.push_back(a[i]); s1+=a[i];
			}else
			if(a[i]>0){
				v2.push_back(a[i]); s2+=a[i];
			}else
			v3.push_back(a[i]);
		}
		if(s1+s2==0){
			printf("NO\n");
		}else{
			printf("YES\n");
			if(s1+s2<0){
				for(auto x:v1)printf("%d ", x);
				for(auto x:v2)printf("%d ", x);
				for(auto x:v3)printf("%d ", x);
			}else{
				for(auto x:v2)printf("%d ", x);
				for(auto x:v1)printf("%d ", x);
				for(auto x:v3)printf("%d ", x);
			}
		}
	}
}