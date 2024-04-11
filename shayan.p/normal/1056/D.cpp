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

vector<int> v[maxn],vec;
int SZ[maxn],arr[maxn];

void dfs(int u){
    SZ[u]=sz(v[u])==0;
    for(int y:v[u]){
	dfs(y);
	SZ[u]+=SZ[y];
    }
    vec.PB(SZ[u]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=2;i<=n;i++){
	int x;cin>>x;
	v[x].PB(i);
    }
    dfs(1);
    sort(vec.begin(),vec.end());
    for(int i=0;i<sz(vec);i++){
	arr[i+1]=vec[i];
    }
    for(int i=n;i>0;i--){
	arr[i]=(arr[i]==0?arr[i+1]:arr[i]);
    }
    for(int i=1;i<=n;i++){
	cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}