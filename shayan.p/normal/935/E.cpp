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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=1e4+10;
const ll MAX=110;

const ll rel=1e5;
const ll open=1e18;
const ll close=-1e18;
const ll impos=2e18;
const ll hsh=3e18;

#pragma GCC Optimize("Ofast")

stack<ll>st;
vector<ll>inp;

ll id;
ll mx[maxn+10][MAX+10];
ll mn[maxn+10][MAX+10];
ll p,n;

void input(){
	string s;cin>>s;
	cin>>p>>n;
	REP(i,sz(s)){
		if(s[i]==')')
			inp.PB(close);
		else if(s[i]=='(')
			inp.PB(open);
		else if(s[i]!='?')
			inp.PB(s[i]-'0');
	}
}

void chmx(ll &a,ll b,ll c){
	ll num=-impos;
	if(abs(impos-b)<=rel||abs(-impos-b)<=rel)b=impos;
	if(abs(impos-c)<=rel||abs(-impos-c)<=rel)c=impos;
	
	if(b!=impos)num=max(num,b);
	if(c!=impos)num=max(num,c);
	if(num==-impos)num=impos;
	a=num;
}
void chmn(ll &a,ll b,ll c){
	ll num=impos;
	if(abs(impos-b)<=rel||abs(-impos-b)<=rel)b=impos;
	if(abs(impos-c)<=rel||abs(-impos-c)<=rel)c=impos;
	
	if(b!=impos)num=min(num,b);
	if(c!=impos)num=min(num,c);
	a=num;
}

ll pl(ll a,ll b){
	if(a==impos||a==-impos)
		return impos;
	if(b==impos||b==-impos)
		return impos;
	return a+b;
}

void solve1(){
	REP(i,sz(inp)){
		if(inp[i]==close){
			ll s=st.top();st.pop();
			ll f=st.top();st.pop();
			st.pop();
			if(f<hsh&&s<hsh){
				mn[id][0]=mx[id][0]=f+s;
				mn[id][1]=mx[id][1]=f-s;
			}
			else if(f<hsh){
				s-=hsh;
				mn[id][0]=mx[id][0]=f+mn[s][0];
				FOR(q,1,MAX-1){
					chmn(mn[id][q],f+mn[s][q],f-mx[s][q-1]);
					chmx(mx[id][q],f+mx[s][q],f-mn[s][q-1]);
				}
			}
			else if(s<hsh){
				f-=hsh;
				mn[id][0]=mx[id][0]=mn[f][0]+s;
				FOR(q,1,MAX-1){
					chmn(mn[id][q],mn[f][q]+s,mn[f][q-1]-s);
					chmx(mx[id][q],mx[f][q]+s,mx[f][q-1]-s);
				}
			}
			else{
				f-=hsh;s-=hsh;
				REP(t,MAX){// mosbat bashe beineshoon
					FOR(q,0,t){
						chmn(mn[id][t],mn[id][t],pl(mn[f][q],mn[s][t-q]));
						chmx(mx[id][t],mx[id][t],pl(mx[f][q],mx[s][t-q]));
					}
				}
				FOR(t,1,MAX-1){
					FOR(q,0,t-1){
						chmn(mn[id][t],mn[id][t],pl(mn[f][q],-mx[s][t-1-q]));
						chmx(mx[id][t],mx[id][t],pl(mx[f][q],-mn[s][t-1-q]));
					}
				}
			}
			st.push(id+hsh);
			id++;
		}
		else{
			st.push(inp[i]);
		}
	}
	cout<<mx[id-1][n];
}

void solve2(){
	REP(i,sz(inp)){
		if(inp[i]==close){
			ll s=st.top();st.pop();
			ll f=st.top();st.pop();
			st.pop();
			if(f<hsh&&s<hsh){
				mn[id][0]=mx[id][0]=f-s;
				mn[id][1]=mx[id][1]=f+s;
			}
			else if(f<hsh){
				s-=hsh;
				mn[id][0]=mx[id][0]=f-mn[s][0];
				FOR(q,1,MAX-1){
					chmn(mn[id][q],f-mx[s][q],f+mn[s][q-1]);
					chmx(mx[id][q],f-mn[s][q],f+mx[s][q-1]);
				}
			}
			else if(s<hsh){
				f-=hsh;
				mn[id][0]=mx[id][0]=mn[f][0]-s;
				FOR(q,1,MAX-1){
					chmn(mn[id][q],mn[f][q]-s,mn[f][q-1]+s);
					chmx(mx[id][q],mx[f][q]-s,mx[f][q-1]+s);
				}
			}
			else{
				f-=hsh;s-=hsh;
				REP(t,MAX){// manfi bashe beineshoon
					FOR(q,0,t){
						chmn(mn[id][t],mn[id][t],pl(mn[f][q],-mx[s][t-q]));
						chmx(mx[id][t],mx[id][t],pl(mx[f][q],-mn[s][t-q]));
					}
				}
				FOR(t,1,MAX-1){
					FOR(q,0,t-1){
						chmn(mn[id][t],mn[id][t],pl(mn[f][q],mn[s][t-1-q]));
						chmx(mx[id][t],mx[id][t],pl(mx[f][q],mx[s][t-1-q]));
					}
				}
			}
			st.push(id+hsh);
			id++;
		}
		else{
			st.push(inp[i]);
		}
	}
	cout<<mx[id-1][p];
}

int main(){
	input();
	if(sz(inp)==1){
		cout<<inp[0];
		return 0;
	}
	REP(i,maxn){
		REP(j,MAX){
			mx[i][j]=impos;
			mn[i][j]=impos;
		}
	}
	if(p>n)
		solve1();
	else
		solve2();
}