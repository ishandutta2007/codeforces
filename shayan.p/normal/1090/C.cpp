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

vector<pair<pii,int> >ans;
set<int>s[maxn];
vector<int> st;
set<pii>ssz;

int main(){
    int n,m,sm=0;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
	int cnt;scanf("%d",&cnt);
	sm+=cnt;
	while(cnt--){
	    int x;scanf("%d",&x);
	    s[i].insert(x);
	}
	ssz.insert({sz(s[i]),i});
    }
    int N1=sm/n,N2=(sm+n-1)/n;
    while(abs((ssz.begin()->F)-(ssz.rbegin()->F))>1){
	int id1=ssz.begin()->S,id2=ssz.rbegin()->S,S1=sz(s[id1]),S2=sz(s[id2]);
	ssz.erase(ssz.begin());ssz.erase(--ssz.end());
	st.clear();
	for(int x:s[id1]){
	    if(s[id2].count(x))
		st.PB(x);
	    s[id2].erase(x);
	}
	if(S1==N1 || S2==N2){
	    ans.PB({{id2,id1},*s[id2].begin()});
	    s[id1].insert(*s[id2].begin());
	    s[id2].erase(s[id2].begin());
	}
      	while(S1<N1 && S2>N2){
	    ans.PB({{id2,id1},*s[id2].begin()});
	    s[id1].insert(*s[id2].begin());
	    s[id2].erase(s[id2].begin());
	    S1++;S2--;
	}
	for(int x:st)
	    s[id2].insert(x);
	ssz.insert({sz(s[id1]),id1});
	ssz.insert({sz(s[id2]),id2});
    }
    printf("%d\n",sz(ans));
    for(auto it:ans)
	printf("%d %d %d\n",it.F.F+1,it.F.S+1,it.S);
    return 0;
}