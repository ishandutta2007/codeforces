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

pii p[3];
set<pii>s;

void Do1(int a,int b,int c){
    for(int i=a;i<=b;i++)
	s.insert({i,c});
}
void Do2(int a,int b,int c){
    for(int i=a;i<=b;i++)
	s.insert({c,i});
}
bool cmp1(pii a,pii b){
    return a.F<b.F;
}
bool cmp2(pii a,pii b){
    return a.S<b.S;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>p[0].F>>p[0].S>>p[1].F>>p[1].S>>p[2].F>>p[2].S;
    sort(p,p+3,cmp1);
    Do1(p[0].F,p[1].F,p[0].S);
    Do1(p[1].F,p[2].F,p[2].S);
    pii P=p[1];
    sort(p,p+3,cmp2);
    Do2(p[0].S,p[2].S,P.F);
    cout<<sz(s)<<endl;
    for(pii x:s)
	cout<<x.F<<" "<<x.S<<"\n";
    return 0;
}