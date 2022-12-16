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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=3e5+10;

bool deleted[maxn];
ll bef[maxn],aft[maxn];
queue<ll>q[maxn];
ll tail=inf;
ll head=inf;
ll cnt=0;

void del(ll u){
	deleted[u]=1;
	if(head==tail&&u==head){
		head=tail=inf;
		return;
	}
	if(u==head){
		head=aft[head];
		return;
	}
	if(u==tail){
		tail=bef[tail];
		return;
	}
	ll Bf=bef[u],Af=aft[u];
	aft[Bf]=Af;
	bef[Af]=Bf;
}

int main(){
	ll n,query,ans=0;cin>>n>>query;
	fill(bef,bef+maxn,inf);
	fill(aft,aft+maxn,inf);
	REP(i,query){
		ll t,x;cin>>t>>x;
		if(t==1){
			q[x].push(cnt);
			ans++;
			if(tail==inf&&head==inf){
				tail=head=cnt++;
			}
			else{
				bef[cnt]=tail;
				aft[tail]=cnt;
				tail=cnt;
				cnt++;
			}
		}
		if(t==2){
			while(sz(q[x])){
				ll fr=q[x].front();
				q[x].pop();
				if(deleted[fr])
					continue;
				del(fr);
				ans--;
			}
		}
		if(t==3){
			while(head<x){
				del(head);
				ans--;
			}
		}
		cout<<ans<<endl;
	}
}