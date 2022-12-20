// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const int maxn=15e5;
const int MAX=5e5+10;

#pragma GCC Optimize("Ofast")

int pre[MAX],suf[MAX],z[maxn];

void Z(string &p,string &t){//pattern // total
	string S=p+"$"+t;
	int L=0,R=0;
	REP(i,sz(S)){
		if(i>R){
			L=R=i;
			while(R<sz(S)&&S[R]==S[R-L])
				R++;
			R--;
			z[i]=R-L+1;
		}
		else{
			if(R-i+1>z[i-L]){
				z[i]=z[i-L];
			}
			else{
				L=i;
				while(S[R]==S[R-L])
					R++;
				R--;
				z[i]=R-L+1;
			}
		}
	}
}

int n,m,k;
vector<int>st[MAX];

void pos(int a,int b){
	if(a<0||a+k>n||b<0||b+k>n||a+k>b)
		return;
	cout<<"Yes\n";
	cout<<a+1<<" "<<b+1;
	exit(0);
}

int main(){
	cin>>n>>m>>k;
	string s,p;cin>>s>>p;
	Z(p,s);
	FOR(i,(m+1),(n+m))
		pre[i-m-1]=z[i];
	reverse(s.begin(),s.end());
	reverse(p.begin(),p.end());
	Z(p,s);
	FOR(i,(m+1),(m+n))
		suf[n-1-(i-m-1)]=z[i];
	REPD(i,n){
		st[suf[i]].PB(i);
	}
	REP(i,n){
		if(pre[i]==m){
			int L=max(0,i+m-(2*k));
			pos(L,L+k);
		}
	}
	int lst=0,pt=m;
	REP(i,n){
		pre[i]=min(pre[i],k);
		if(pre[i]<=lst)
			continue;
		lst=pre[i];
		while(pt>=(m-lst)){
			while(!st[pt].empty()){
				int R=st[pt].back();
				st[pt].POB();
				int L=R-(m-lst)+1;
				pos(i+lst-k,L);
			}
			pt--;
		}
	}
	cout<<"No";
}