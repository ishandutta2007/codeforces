// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define POB pop_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii>v[maxn];// to // edge id
vector<int>ans;

void find_cycle(int u){
    vector<pii>vec;
    while(!v[u].empty()){
	int U=u;
	u=v[U].back().F;
	vec.PB({v[U].back()});
	v[U].POB();
    }
    for(pii p:vec){
	ans.PB(p.S);
	find_cycle(p.F);
    }
}

int main(){
    int n;scanf("%d",&n);
    if(n&1){
	printf("-1\n");
	return 0;
    }
    int N=n/2;
    for(int i=n-1;i>=0;i--){
	v[i/2].PB({i%N,i});
    }
    find_cycle(0);// is connected
    for(int x:ans)
	printf("%d ",x);
    printf("0 \n");
}