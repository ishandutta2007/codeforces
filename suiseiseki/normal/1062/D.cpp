#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	ll ans;
	int n;
    scanf("%d",&n);
    ans=0;
    for(int i=2;i<=n;i++){
        ans+=(4ll*(n/i-1))*i;
    }
    cout<<ans<<endl;
    return 0;
}