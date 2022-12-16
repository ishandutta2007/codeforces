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

set<pii>s1,s2;

pii p1[2],p2[4];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    p1[0]={1,1};
    p1[1]={3,1};
    p2[0]={1,2};
    p2[1]={2,2};
    p2[2]={3,2};
    p2[3]={4,2};
    for(char ch:s){
	if(s1.empty()) for(int i=0;i<2;i++) s1.insert(p1[i]);
	if(s2.empty()) for(int i=0;i<4;i++) s2.insert(p2[i]);
	if(ch=='0'){
	    pii pp=*s1.begin();
	    s1.erase(pp);
	    cout<<pp.F<<" "<<pp.S<<"\n";
	}
	else{
	    pii pp=*s2.begin();
	    s2.erase(pp);
	    cout<<pp.F<<" "<<pp.S<<"\n";
	}
    }
    return 0;
}