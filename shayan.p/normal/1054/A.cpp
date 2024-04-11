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

int main(){
    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int A=abs(x-y)*t1;
    int B=(abs(x-z)+abs(x-y))*t2+3*t3;
    cout<<((B<=A)?"YES":"NO")<<endl;
    return 0;
}