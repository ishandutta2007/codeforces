// Can U hack it?

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

ll arr[100];

int main(){
    arr[0]=1;
    arr[1]=2;
    for(int i=2;i<100;i++)
	arr[i]=arr[i-1]+arr[i-2];
    ll n;cin>>n;
    cout<<upper_bound(arr,arr+100,n)-1-arr<<endl;
    return 0;
}