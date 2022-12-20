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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,b;cin>>a>>b;
    int C;cin>>C;
    reverse(a.begin(),a.end());
    int A=0;
    for(int i=0,tn=1;i<sz(a);i++,tn=10ll*tn %C)
	A=(1ll*A+1ll*tn*(a[i]-'0'))%C;
    reverse(b.begin(),b.end());
    int pt=0;
    while(--b[pt]<'0')
	b[pt++]='9';
    int ans=A-1;
    for(int i=0;i<sz(b);i++){
	for(int j=0;j<b[i]-'0';j++)
	    ans=1ll*ans*A %C;
	int num=1;
	for(int j=0;j<10;j++)
	    num=1ll*num*A %C;
	A=num;
    }
    if(ans<=0) ans+=C;
    cout<<ans<<endl;
}