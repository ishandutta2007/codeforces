// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n;
vector<int> factor,ans;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a %n;
	a=1ll*a*a %n;
	b>>=1;
    }
    return ans;
}

bool prime(int n){
    for(int i=2;i*i<=n;i++)
	if(n%i==0)
	    return 0;
    return 1;
}

void factorize(int n){
    for(int i=2;i*i<=n;i++){
	if(n%i==0)
	    factor.PB(i);
	while(n%i==0)
	    n/=i;
    }
    if(n>1)
	factor.PB(n);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    if(n==2)
	return cout<<"YES\n1 2\n",0;
    if(n==4)
	return cout<<"YES\n1 3 2 4\n",0;
    if(!prime(n))
	return cout<<"NO\n",0;
    factorize(n-1);
    int g=-1;
    for(int i=1;i<n;i++){// looking for primitive root
	bool no=0;
	for(int x:factor)
	    no|=Pow(i,(n-1)/x)==1;
	if(no==0){
	    g=i;
	    break;
	}
    }
    for(int i=0;i<n-1;i++){
	ans.PB(Pow(g,(i&1?-1:1)*i+n-1));
    }
    ans.PB(n);
    cout<<"YES\n";
    for(int x:ans)
	cout<<x<<"\n";
    return 0;
}