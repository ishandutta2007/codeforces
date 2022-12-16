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

int tdo[maxn];

pii ASK(int pos){
    cout<<"? "<<pos<<endl;
    int A,B;cin>>A>>B;
    return {A,B};
}
void ANS(int x){
    cout<<"! "<<x<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    srand(time(0));
    int n,start,x;cin>>n>>start>>x;
    for(int i=1;i<=n;i++)
	tdo[i]=i;
    random_shuffle(tdo+1,tdo+n+1);
    int val=ASK(start).F;
    for(int i=1;i<=min(n,999);i++){
	pii p=ASK(tdo[i]);
	if(p.F<x && val<p.F) start=tdo[i],val=p.F;
    }
    while(val<x && start!=-1){
	pii p=ASK(start);
	start=p.S;
	val=p.F;
    }
    if(val<x)
	ANS(-1);
    else
	ANS(val);
    return 0;
}