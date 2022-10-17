#include <set>
#include <cstdio>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
set<int> st;
int n,q;
int left[Maxn+5],right[Maxn+5];
int sum[Maxn+5];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=Maxn;i++){
		left[i]=n+1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		left[a[i]]=min(left[a[i]],i);
		right[a[i]]=max(right[a[i]],i);
		sum[a[i]]++;
	}
	int ans=0;
	int s,maxn,mx=0;
	set<int>::iterator it;
	for(int i=1;i<=n;i++){
		st.insert(a[i]);
		mx=max(mx,right[a[i]]);
		if(mx<=i){
			s=maxn=0;
			it=st.begin();
			while(it!=st.end()){
				maxn=max(maxn,sum[(*it)]);
				s+=sum[(*it)];
				it++;
			}
			ans+=s-maxn;
			st.clear();
			mx=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}