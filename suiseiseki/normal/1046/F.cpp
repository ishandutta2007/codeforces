#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
int a[200005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int f,x;
	scanf("%d%d",&x,&f);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]/(x+f);
		if(a[i]%(x+f)>x){
			ans++;
		}
	}
	cout<<ans*f<<endl;
	return 0;
}