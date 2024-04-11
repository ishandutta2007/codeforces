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

const int maxn=1e6+10, LG=21;

int sp[LG][maxn], arr[maxn];
int mn[maxn];
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string s; cin>>s;
    int n=sz(s), SM=0;
    for(int i=0;i<n;i++){
	SM+= s[i]=='(' ? 1 : -1;
    }
    for(int i=0;i<n;i++){
	sp[0][i]= s[i]==')';
	arr[i]=i;
    }
    int lg=0;
    for(int i=1;(1<<i)<=n;i++){
	lg=i;
	int pw=1<<(i-1);
	auto f= [&](int a,int b){
	    if(sp[i-1][a] != sp[i-1][b]) return sp[i-1][a] < sp[i-1][b];
	    a+=pw, b+=pw;
	    if(a>=n) a-=n;
	    if(b>=n) b-=n;
	    return sp[i-1][a] < sp[i-1][b];		
	};
	sort(arr,arr+n,f);
	for(int j=1;j<n;j++){
	    sp[i][arr[j]]= sp[i][arr[j-1]] + (f(arr[j-1],arr[j]) || f(arr[j],arr[j-1]));
	}
    }
    for(int i=0;i<n;i++){
	mn[i]=(i==0 ? 0 : mn[i-1]) + (s[i]=='(' ? 1 : -1);
    }
    for(int i=1;i<n;i++){
	mn[i]=min(mn[i-1],mn[i]);
    }
    int sm=0, mm=0, pos=-1;

    auto cmp= [&](int a,int b){
	int lc=0;
	for(int i=lg;i>=0;i--){
	    if(lc+(1<<i)<=n && sp[i][a]==sp[i][b]) a+=(1<<i), b+=(1<<i), lc+=(1<<i), a%=n, b%=n;
	}
	return s[a]<s[b];
    };

    for(int i=n-1;i>=0;i--){
	int x= s[i]=='(' ? 1 : -1;
	mm+=x;
	sm+=x;
	mm=min(mm,x);
	int bf=(i==0 ? 0 : mn[i-1]);
	if(min(mm, sm+bf) + max(-SM,0) >=0){
	    if(pos==-1) pos=i;
	    else if(cmp(i,pos)) pos=i; 
	}
    }
    
    string ans, ss;
    for(int i=0;i<n;i++){
	ans+= s[(i+pos)%n];
    }
    if(SM<0){
	while(SM<0) ss+='(', SM++;
	ans=ss+ans;
    }
    else{
	while(SM>0) ss+=')', SM--;
	ans=ans+ss;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")