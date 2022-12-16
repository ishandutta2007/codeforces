// Can U hack it?

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
    string s;cin>>s;
    bool rev=(s[0]=='b');
    for(int i=1;i<sz(s);i++){
	if((s[i]=='a')^rev)
	    cout<<1<<" ",rev^=1;
	else
	    cout<<0<<" ";
    }
    if(rev)
	cout<<1<<" ";
    else
	cout<<0<<" ";
    cout<<endl;
    return 0;
}