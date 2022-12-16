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

const ll maxn=153;

vector< bitset<maxn> >is,wl,chk;
bitset<maxn>sv[maxn],rem[maxn];
int n,m,k;
string tdo;

void input(){
    cin>>n>>m>>k;
    is.resize(n+2);
    wl.resize(n+2);
    chk.resize(n+2);
    string str;
    REP(i,n){
	cin>>str;
	REP(j,m){
	    if(str[j]!='#')
		is[i][j]=wl[i][j]=1;
	    if(str[j]=='E')
		chk[i][j]=1;
	}
    }
    cin>>tdo;
}

int main(){
    input();
    REP(w,sz(tdo)){
	if(chk==is){
	    cout<<w;
	    return 0;
	}
	memset(sv,0,sizeof sv);
	memset(rem,0,sizeof rem);
	if(tdo[w]=='U'){
	    REP(i,n){
		rem[i]=is[i+1]&wl[i];
		is[i]=is[i+1];
	    }
	    REP(i,n){
		sv[i]=rem[i]^is[i];
	    }
	    FORD(i,n-1,1){
		sv[i]=sv[i-1];
	    }
	    sv[0]=0;
	    REP(i,n){
		is[i]=rem[i]|sv[i];
	    }
	}
	if(tdo[w]=='D'){
	    FORD(i,n-1,1){
		rem[i]=is[i-1]&wl[i];
		is[i]=is[i-1];
	    }
	    is[0]=rem[0]=0;
	    REP(i,n){
		sv[i]=rem[i]^is[i];
	    }
	    REP(i,n){
		sv[i]=sv[i+1];
	    }
	    REP(i,n){
		is[i]=rem[i]|sv[i];
	    }
	}
	if(tdo[w]=='R'){
	    REP(i,n){
		rem[i]=(is[i]<<1)&wl[i];
		sv[i]=rem[i]^(is[i]<<1);
		rem[i][0]=sv[i][0]=0;
		is[i]=rem[i]|(sv[i]>>1);
	    }
	}
	if(tdo[w]=='L'){
	    REP(i,n){
		rem[i]=(is[i]>>1)&wl[i];
		sv[i]=rem[i]^(is[i]>>1);
		is[i]=rem[i]|(sv[i]<<1);
	    }
	}
	if(chk==is){
	    cout<<w+1;
	    return 0;
	}
    }
    cout<<-1;
}