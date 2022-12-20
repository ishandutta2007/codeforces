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

vector<int>v1,v2;
int a[maxn],n;

void normal(vector<int>&v){
    int pos=0;
    for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1)
	    pos=i;
    }
    for(int i=0;i<n;i++){
	if(a[(i+pos)%n]!=0)
	    v.PB(a[(i+pos)%n]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    normal(v1);
    normal(v2);
    cout<<(v1==v2?"YES":"NO")<<endl;
    return 0;
}