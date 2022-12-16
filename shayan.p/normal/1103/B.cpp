// Wanna Hack? GL...

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

bool Ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    char ch;cin>>ch;
    return ch=='x';
}

void solve(){
    int l=0;
    while(!Ask(l,2*l+1)) l=2*l+1;
    int r=2*l+1;
    while(r-l>1){
	int mid=(l+r)>>1;
	if(Ask(mid/2,mid)) r=mid;
	else               l=mid;
    }
    cout<<"! "<<r<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string S;cin>>S;
    while(S=="start"){
	solve();
	cin>>S;
    }
    return 0;
}