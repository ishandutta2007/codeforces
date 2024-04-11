// Mikaeel_noob_e_sag_e

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

vector<pii> ans;

void add(int num){
    for(pii p:ans){
	if(bit(num,p.S))
	    num^=p.F;
    }
    if(num==0) return;
    int id=__builtin_ctz(num);
    for(pii &p:ans){
	if(bit(p.F,id))
	    p.F^=num;
    }
    ans.PB({num,id});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int num=0;
    while(n--){
	int x;cin>>x;
	add(num=num^x);
    }
    if(num==0) return cout<<-1<<endl,0;
    cout<<sz(ans)<<endl;
    return 0;
}