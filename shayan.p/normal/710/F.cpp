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

const int maxn=3e5+10,mod=1e9+7,P1=31,P2=107;

pii operator * (pii a,pii b){
    int A=1ll*a.F*b.F %mod;
    int B=1ll*a.S*b.S %mod;
    if(A<0) A+=mod;
    if(B<0) B+=mod;
    return {A,B};
}
pii operator + (pii a,pii b){
    int A=(a.F+b.F);
    int B=(a.S+b.S);
    if(A>=mod) A-=mod;
    if(B>=mod) B-=mod;
    return {A,B};
}
pii operator - (pii a,pii b){
    int A=(a.F-b.F);
    int B=(a.S-b.S);
    if(A<0) A+=mod;
    if(B<0) B+=mod;
    return {A,B};
}
ostream &operator<<(ostream &out,pii a){
    return out<<a.F<<" "<<a.S;
}

map<int,set<pii> >mp;
pii hsh[maxn],pw[maxn];

void Do(string &s){
    for(int i=1;i<=sz(s);i++){
	hsh[i]=(hsh[i-1]*pw[1])+(pii){s[i-1]-'a'+1,s[i-1]-'a'+1};
    }
}
inline pii Hash(int l,int r){
    return hsh[r]-(hsh[l-1]*pw[r-l+1]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    pw[0]={1,1};
    pw[1]={P1,P2};
    for(int i=2;i<maxn;i++)
	pw[i]=pw[i-1]*pw[1];
    int m;cin>>m;
    while(m--){
	int task;cin>>task;
	string s;cin>>s;
	Do(s);
	if(task==1){
	    mp[sz(s)].insert(hsh[sz(s)]);
	}
	if(task==2){
	    mp[sz(s)].erase(hsh[sz(s)]);
	}
	if(task==3){
	    ll ans=0;
	    for(auto &x:mp){
		for(int i=1;i<=sz(s)-x.F+1;i++){
		    ans+=x.S.count(Hash(i,i+x.F-1));
		}
	    }
	    cout<<ans<<endl;
	}
    }
}