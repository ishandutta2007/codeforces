#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	int n;
	scanf("%d",&n);
	int la=0,lb=0;
	int a,b;
	ll ans=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a==la&&b==lb){
			continue;
		}
		if(la==lb){
			ans+=min(a,b)-la;
		}
		else{
			if(la<lb){
				if(a==b){
					ans+=a-lb+1;
				}
				else if(a<b){
					if(a>=lb){
						ans+=a-lb+1;
					}
				}
				else{
					ans+=b-lb+1;
				}
			}
			else{
				if(a==b){
					ans+=a-la+1;
				}
				else if(b<a){
					if(b>=la){
						ans+=b-la+1;
					}
				}
				else{
					ans+=a-la+1;
				}
			}
		}
		la=a;
		lb=b;
	}
	cout<<ans<<endl;
	return 0;
}