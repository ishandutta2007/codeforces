// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=5e4+10,maxk=11,inf=1e9;

ordered_set<int>s[maxk];
map<pii,int>mp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    while(n--){
	int mn=inf,mx=-inf,start=-1;
	for(int i=0;i<k;i++){
	    int x;cin>>x;
	    x*=-1;
	    if(i==0) start=x;
	    int num=s[i].order_of_key(x);
	    s[i].insert(x);
	    mn=min(mn,num);mx=max(mx,num);
	}
	auto it=mp.upper_bound({start,-1});
	if(it==mp.begin() || (prev(it)->F.S)<start)
	    mp[{start,start}]++,it=mp.find({start,start});
	else
	    mp[prev(it)->F]++,it=prev(it);
	while(int(s[0].order_of_key(it->F.F))>mn){
	    int L=prev(it)->F.F,R=it->F.S,C=(prev(it)->S)+(it->S);
	    mp.erase(prev(it));mp.erase(it);mp[{L,R}]=C;
	    it=mp.find({L,R});
	}
	while(int(s[0].order_of_key(it->F.S))<mx){
	    int L=it->F.F,R=next(it)->F.S,C=(next(it)->S)+(it->S);
	    mp.erase(next(it));mp.erase(it);mp[{L,R}]=C;
	    it=mp.find({L,R});
	}
	cout<<mp.begin()->S<<"\n";
    }
}