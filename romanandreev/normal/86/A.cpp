#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
ll prod(ll a){
	ll b=0;
	ll tk=1;
	while (a>0){
		b=b+(9-a%10)*tk;
		a/=10;
		tk*=10;
	}
	return b;
}
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int l,r;
    cin>>l>>r;
    ll ans=max(prod(l)*l,prod(r)*r);
    ll tk=1;
    for (int i=1;i<=9;i++){
    	if (5*tk>=l && 5*tk<=r){
    		ans=max(ans,prod(5*tk)*5*tk);
    	}
    	tk*=10;
    }
    cout<<ans<<endl;   
    return 0;
}