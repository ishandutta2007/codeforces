// Wanna Hack? GL...

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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

int f[maxn],A,B;
string s,ans;

bool Add(int l,int r){
    int aa=0,bb=0;
    for(int i=l;i<r;i++){
	if(s[i]=='0') aa++;
	else          bb++;
    }
    if(aa<=A && bb<=B) A-=aa,B-=bb;
    else return 0;
    for(int i=l;i<r;i++){
	ans+=s[i];
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a;cin>>a>>s;
    f[0]=-1;
    f[1]=0;
    for(int i=2;i<=sz(s);i++){
	f[i]=f[i-1];
	while(f[i]>0 && s[f[i]]!=s[i-1]) f[i]=f[f[i]];
	f[i]+=(s[i-1]==s[f[i]]);
    }
    for(int i=0;i<sz(a);i++){
	if(a[i]=='0') A++;
	else          B++;
    }
    if(Add(0,sz(s))){
	while(Add(f[sz(s)],sz(s))){
	}
    }
    while(A){
	ans+="0";
	A--;
    }
    while(B){
	ans+="1";
	B--;
    }
    return cout<<ans<<endl,0;
}