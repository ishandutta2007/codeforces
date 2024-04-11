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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

pii p[maxn];
int ans[maxn];

set<int>st;
map<int,int>mp;

void Delete(int pos){
    auto it2=st.upper_bound(pos),it1=prev(it2);
    st.insert(pos);
    if(--mp[(*it2)-(*it1)-1]==0) mp.erase((*it2)-(*it1)-1);
    mp[pos-(*it1)-1]++;
    mp[(*it2)-pos-1]++;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    st.insert(-1);
    st.insert(n);
    mp[n]++;
    for(int i=0;i<n;i++){
	cin>>p[i].F;
	p[i].S=i;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
	int bef=mp.rbegin()->F;
	Delete(p[i].S);
	int nw=mp.rbegin()->F;
	for(int j=bef;j>nw;j--)
	    ans[j]=p[i].F;
    }
    for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}