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
 
const int maxq = 5e4 + 10, maxc = 5e6 + 10, maxs=9 * 18 + 3, maxt = 3;
const ll Big=1e18;
 
int pas[30][30];
 
//bitset<maxs> dp[maxc];
bitset<maxs> dp;
vector<int> anses[20];
 
bool done[maxc];
 
ll val[maxc][maxt];
 
void go(int dig=9, int rem=18, int msk=0, int id=0){
    if(dig==0){
	int ans=-1;
	for(int i=9; i>=0; i--)
	    if(dp[i])
		ans=i;
	anses[ans].PB(id);
	return;
    }
    bitset<maxs> _dp = dp;
    
    int pos= msk==0 ? (0) : (32-__builtin_clz(msk));
    while(true){	
	go(dig-1, rem, msk | (1<<pos), id + pas[pos][9-dig+1]);
	rem--, pos++;
	if(rem<0) break;
	int tdo=0;
	for(int i=0;i<dig;i++)
	    if(dp[i])
		tdo|=1<<(dig-i);
	dp = (dp<<dig) | (dp>>dig);
	for(int i=0;i<dig;i++)
	    if(bit(tdo,i))
		dp[i]=1;
    }
    dp = _dp;
}
 
/*
void go(){
    int msk=(1<<9)-1, lim=(1<<(17+9)), id=0;
    dp[0][0] = 1;
    
    while(msk < lim){
	int ID=id, MSK = msk;
	
	int res=0;
	for(int i=9; i>=0; i--)
	    if(dp[id][i])
		res=i;
	anses[res].PB(id);
	
	for(int i=1; i<10; i++){
	    int pos= 31-__builtin_clz(MSK);
	    MSK^=1<<pos;
	    ID-= pas[pos][9-i+1];
	    ID+= pas[pos+1][9-i+1];
	    
	    if(done[ID] == 0){
		done[ID] = 1;
 
		dp[ID] = (dp[id]<<i) | (dp[id]>>i);
		for(int j=0; j<i; j++)
		    if(dp[id][j])
			dp[ID][i-j]=1;			
	    }
	}
 
	int mb = msk & -msk;
	int mmb = msk + mb;
	
	msk = mmb + (1<<(__builtin_ctz(mmb) - __builtin_ctz(msk) -1)) - 1;
	id++;
    }
    }*/
 
 
void go2(int rem){
    int msk=(1<<9)-1, lim=(1<<(rem+9)), id=0;
    while(msk < lim){
	int ID=id, MSK = msk;
	for(int i=1; i<10; i++){
	    int pos= 31-__builtin_clz(MSK);
	    MSK^=1<<pos;
	    ID-= pas[pos][9-i+1];
	    ID+= pas[pos+1][9-i+1];
	    for(int j=0; j<maxt; j++)
		val[id][j]+= val[ID][j];
	}
 
	int mb = msk & -msk;
	int mmb = msk + mb;
	
	msk = mmb + (1<<(__builtin_ctz(mmb) - __builtin_ctz(msk) -1)) - 1;
	id++;
    }
}
    
    
struct SetOfDigs{
    int pos[10];
 
    SetOfDigs(){
	for(int i=9;i>0;i--)
	    pos[i]=9-i;
    }
    int calc(){
	int ans=0;
	for(int i=9; i>0; i--)
	    ans+= pas[pos[i]][9-i+1];
	return ans;
    }
    int calc9(){
	for(int i=8; i>0; i--)
	    if(pos[i]-1 != pos[i+1])
		return -1;
	return pos[9];
    }
    void add(int x){
	for(int i=x; i>0; i--)
	    pos[i]++;
    }
    void era(int x){
	for(int i=x; i>0; i--)
	    pos[i]--;
    }
};
    
SetOfDigs sd;
 
vector<int> tdo[maxq][20];
int K[maxq];

vector<pii> tdo9[20];

void qToVec(ll f, ll s, int index, ll l=0, ll r=Big, int rem=18){
    if( f<=l && r<=s ){
	//	tdo[rem].PB( { {sd.calc(), index}, k} );
	tdo[index][rem].PB( sd.calc() ); 
	if(K[index]==9)
	    tdo9[rem].PB( { sd.calc9(), index } );
	return;
    }
    ll df=(r-l)/10;
    ll L=l, R=L+df;
    for(int i=0; i<10; i++, L+=df, R+=df){
	if( s<=L || R<=f ) continue;
	sd.add(i);
	qToVec(f, s, index, L, R, rem-1);
	sd.era(i);
    }
}
 
ll ans[maxq];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
 
    for(int i=0;i<30;i++){
	pas[i][i]= pas[i][0]= 1;
	for(int j=1;j<i;j++)
	    pas[i][j]= pas[i-1][j] + pas[i-1][j-1];
    }
    int q; cin>>q;
    
    for(int i=0; i<q; i++){
	ll a,b; cin>>a>>b;
	cin>>K[i];
	if( b == Big )
	    ans[i]+= K[i]>=1, b--;
	if(a<=b)
	    qToVec(a, b+1, i); 
    }
 
    dp[0]=1;
    go();
 
    for(int i=0; i<maxt; i++)
	for(int x: anses[i])
	    for(int j=i; j<maxt; j++)
		val[x][j]++;
    for(int i=18; i>=0; i--){
	for(int id=0; id<q; id++)
	    for(auto p: tdo[id][18-i])
		ans[id]+= val[p][min(K[id], maxt-1)];	
	if(i>0)
	    go2(i-1);
    }
 
    memset(val, 0, sizeof val);
    for(int i=maxt; i<2*maxt; i++)
	for(int x: anses[i])
	    for(int j=i; j<2*maxt; j++)
		val[x][j-maxt]++;
 
    for(int i=18; i>=0; i--){
	for(int id=0; id<q; id++)
	    for(auto p: tdo[id][18-i])
		ans[id]+= K[id] < maxt ? 0 : val[p][min(K[id]-maxt, maxt-1)];
	if(i>0)
	    go2(i-1);
    }

    memset(val, 0, sizeof val);
    for(int i=2*maxt; i<3*maxt; i++)
	for(int x: anses[i])
	    for(int j=i; j<3*maxt; j++)
		val[x][j-2*maxt]++;
 
    for(int i=18; i>=0; i--){
	for(int id=0; id<q; id++)
	    for(auto p: tdo[id][18-i])
		ans[id]+= K[id] < 2*maxt ? 0 : val[p][min(K[id]-2*maxt, maxt-1)];	
	if(i>0)
	    go2(i-1);
    }

    auto f = [](int x, int y){
	ll ans=0;
	for(int i= (y&1)^1; i<=x; i+=2)
	    ans+= pas[x][i];
	return ans;
    };
    
    for(int i=0; i<=18; i++){
	for(auto p: tdo9[i])
	    if(p.F != -1)
		ans[p.S]+= f(i, p.F);   
    }
    for(int i=0; i<q; i++){
	cout<<ans[i]<<"\n";
    }   
	    
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.
 
 
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")