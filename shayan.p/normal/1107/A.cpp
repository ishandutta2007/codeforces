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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	int n;cin>>n;
	string s;cin>>s;
	if(n>2 || s[0]<s[1]){
	    cout<<"YES\n2\n"<<s[0]<<" ";
	    for(int i=1;i<n;i++)
		cout<<s[i];
	    cout<<"\n";
	}
	else{
	    cout<<"NO\n";
	}
    }
    return 0;
}