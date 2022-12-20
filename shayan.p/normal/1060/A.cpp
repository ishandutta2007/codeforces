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

int A,B;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
	if(s[i]=='8')A++;
	else B++;
    }
    for(int i=A;i>=0;i--){
	if((A-i+B) >= 10*i){
	    cout<<i<<endl;
	    return 0;
	}
    }
}