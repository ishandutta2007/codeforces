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

map<int,vector<int> >mp;
int ans[maxn],C;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	mp[n-x].PB(i);
    }
    for(auto it:mp){
	if((it.F)==0 || sz(it.S)%it.F!=0)
	    return cout<<"Impossible\n",0;
	for(int i=0;i<sz(it.S);i++){
	    if(i%it.F==0) C++;
	    ans[it.S[i]]=C;
	}
    }
    cout<<"Possible\n";
    for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}