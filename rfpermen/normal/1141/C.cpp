//
/*==========================================================*/
/*    Template ver 2017-0720    |    Created by JollyBee    */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
const double EPS=(double)1e-9;
const double PI=(double)acos(-1.0);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)
#define REP(i,l,r) REPP(i,l,r,1)
#define FORD(i,n) for(int i=n-1;i>=0;i--)
#define REVV(i,l,r,c) for(int i=l;i>=r;i-=c)
#define REV(i,l,r) REVV(i,l,r,1)
//random
int irand(int lo, int hi){
    return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}
//ll to string
string toString(ll x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
//string to ll
ll toNumber(string S) {
    ll ret;
    sscanf(S.c_str(),"%lld",&ret);
    return ret;
}
// std::fill(start, end, value);
// for(auto it: DS){}
 
const int INF=(int)2e9;
const ll MOD=(ll)1e9+7;
/*==========================================================*/
/*                     END OF TEMPLATE                      */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/
 
int dat[200005];
int vis[200005];
 
int main(){
    //reset
    FOR(i,200003) vis[i] = 1;
    //input
    int n; scanf("%d", &n);
    //generate
    int minn = (dat[1] = 1);
    REP(i,2,n){
        int diff; scanf("%d", &diff);
        dat[i] = dat[i-1] + diff;
        minn = min(minn, dat[i]);
    }
    //offsets
    int flag = 1;
    REP(i,1,n){
        dat[i] += -minn + 1;
        if(dat[i] <= n && dat[i]>0) flag &= vis[dat[i]], vis[dat[i]]=0;
        else flag = 0;
    }
    //print
    if(!flag) puts("-1");
    if( flag) REP(i,1,n) printf("%d%c", dat[i], " \n"[i==n]);
    return 0;
}