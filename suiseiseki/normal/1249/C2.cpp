#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100
ll n;
int a[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	int len;
	ll ans=0;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n;
		len=0;
		while(n){
			a[++len]=n%3;
			n/=3;
		}
		for(int i=len;i>0;i--){
			if(a[i]==2){
				a[i]=0;
				a[i+1]++;
				for(int j=i+1;j<=len;j++){
					if(a[j]>=2){
						a[j]=0;
						a[j+1]++;
					}
				}
				for(int j=i-1;j>0;j--){
					a[j]=0;
				}
				break;
			}
		}
		if(a[len+1]>0){
			len++;
			if(a[len]>2){
				a[len]=0;
				a[len+1]++;
				len++;
			}
		}
		ans=0;
		for(int i=len;i>0;i--){
			ans=(ans*3)+a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}