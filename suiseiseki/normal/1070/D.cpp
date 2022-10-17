#include <cstdio>
#include <iostream>
using namespace std;
int a[200005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=0;
	int last_day=0;
	for(int i=1;i<=n;i++){
		a[i]+=last_day;
		if(a[i]<k){
			if(last_day>0){
				ans++;
				a[i]=0;
			}
		}
		ans+=a[i]/k;
		last_day=a[i]%k;
	}
	if(last_day>0){
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}