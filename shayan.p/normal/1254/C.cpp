// Remember...

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

ll ask1(int a,int b,int c){
    cout<<1<<" "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
    ll x; cin>>x;
    return x;
}
bool ask2(int a, int b, int c){
    cout<<2<<" "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
    int x; cin>>x;
    return x==1;
}

ll vl[maxn];

vector<int> v1, v2;
deque<int> an1, an2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;

    for(int i=2;i<n;i++){
	vl[i] = ask1(0,1,i);
	if(ask2(0,1,i)) v1.PB(i);
	else            v2.PB(i);
    }
    sort(v1.begin(), v1.end(), [](int a,int b){ return vl[a]>vl[b]; });
    sort(v2.begin(), v2.end(), [](int a,int b){ return vl[a]>vl[b]; });

    for(int x:v1){
	if(an1.empty()) an1.push_back(x);
	else if(ask2(0, an1.back(), x)) an1.push_back(x);
	else                  an1.push_front(x);
    }
    for(int x:v2){
	if(an2.empty()) an2.push_back(x);
	else if(ask2(0, an2.back(), x)) an2.push_back(x);
	else                            an2.push_front(x);
    }
    cout<<0<<" "<<1<<" ";
    for(int x:an2)
	cout<<x+1<<" ";
    cout<<2<<" ";
    for(int x:an1)
	cout<<x+1<<" ";
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")