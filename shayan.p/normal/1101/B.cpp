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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

string s;

bool srch(char ch){
    while(sz(s) && s.back()!=ch) s.pop_back();
    if(s.empty()) return 0;
    s.pop_back();
    return 1;
}

int main(){
    cin>>s;
    if(!srch(']')) return cout<<-1<<endl,0;
    if(!srch(':')) return cout<<-1<<endl,0;
    reverse(s.begin(),s.end());
    if(!srch('[')) return cout<<-1<<endl,0;
    if(!srch(':')) return cout<<-1<<endl,0;
    int ans=4;
    while(srch('|')) ans++;
    return cout<<ans<<endl,0;
}