// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const int maxn=3e5+10;
const int mdig=1200;
const int mod=1e9+7;
const int Base=1e9;
const int DIG=9;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O1")
#pragma GCC Optimize("O2")
#pragma GCC Optimize("O3")
#pragma GCC Optimize("O4")
#pragma GCC Optimize("O5")

int a[maxn],b[maxn],nm[mdig];
vector<int>ans,vec;

void to_bignum(string &s){
    int res=0,h=0,tn=1;
    REPD(i,sz(s)){
	res=res+tn*(s[i]-'0');
       	if(((sz(s)-1-i)%DIG) == (DIG-1)){
	    nm[h++]=res;
	    res=0;
	    tn=1;
      	}
	else{
	    tn*=10;
	}
    }
    nm[h++]=res;
}

int divrem(int x){
    int rm=0;
    REPD(i,mdig){
	ll XX=ll(rm)*ll(Base)+nm[i];
	rm=int(XX%ll(x));
	nm[i]=int(XX/x);
    }
    REP(i,mdig-1){
	nm[i+1]+=(nm[i]/Base);
	nm[i]%=Base;
    }
    return rm;
}

bool is_zero(){
    REP(i,mdig){
	if(nm[i]!=0)
	    return 0;
    }
    return 1;
}

int main(){
    int n;scanf("%d",&n);
    FOR(i,2,n){
	scanf("%d",&a[i]);
    }
    FOR(i,1,n){
	scanf("%d",&b[i]);
    }
    FOR(i,0,b[1]){
	ans.PB(1);
    }

    string s;cin>>s;
    to_bignum(s);

    bool END=0;
    
    FOR(i,2,n){
	int r=0;
	if(a[i]!=1){
	    r=divrem(a[i]);
	    END=is_zero();
	}
	vec.clear();
	REP(j,sz(ans)){
	    if(j%a[i]==r)
		vec.PB(((vec.empty()?0:vec.back())+ans[j])%mod);
	}
	if(vec.empty()){
	    cout<<0;
	    return 0;
	}
	ans.clear();
	REP(j,sz(vec)+b[i]){
	    int l=max(0,j-b[i]);
	    int r=min(sz(vec)-1,j);
	    ans.PB((vec[r]-(l==0?0:vec[l-1])+mod)%mod);
	}
	if(END)
	    break;
    }
    FOR(i,1,mdig-1){
	if(nm[i]!=0){
	    cout<<0;
	    return 0;
	}
    }
    if((sz(ans)-1)<nm[0])
	  cout<<0;
    else
	cout<<ans[nm[0]];
}