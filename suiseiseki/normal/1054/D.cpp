#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
#define ll long long
ll a[Maxn+5];
map<int,int> num;
int main(){
	ll n,k,p,res,ans,nowc,nowy;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    p=(1<<k)-1;
	ans=n*(n+1)/2;
	num[0]=1;
    for(int i=1;i<=n;i++){
        nowc=res^a[i];
        nowy=nowc^p;
        if(num[nowc]>=num[nowy]){
            res=nowy;
            ans-=num[nowy];
            num[nowy]++;
        }
        else{
            res=nowc;
            ans-=num[nowc];
            num[nowc]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}