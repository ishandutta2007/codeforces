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

const ll inf=1e18;
const ll maxn=2e5+10;


struct node
{
	map<bool,node*> son;
	ll num=0;
};
node start;
void Save(ll p)
{
	node *tmp=&start;
	REP(i,30){
		tmp->num++;
		bool P=(p>>(29-i))%2;
		if((tmp->son).count(P)){
			tmp=(tmp->son)[P];
		}
		else{
			node *newnode=new node();
			(tmp->son)[P]=newnode;
			tmp=newnode;
		}
	}
	tmp->num++;
}
ll Count(ll p,ll l)
{
	ll ans=0;
	node *tmp=&start;
	REP(i,30){
		bool L=(l>>(29-i))%2;
		bool P=(p>>(29-i))%2;
		bool go;
		if(L==0){
			go=P;
		}
		else{
			if(tmp->son.count(P))
				ans+=(tmp->son)[P]->num;
			go=!P;
		}
		if(!tmp->son.count(go))
			break;
		tmp=tmp->son[go];
	}
	return ans;
}
ll Del(ll p){
	node *tmp=&start;
	REP(i,30){
		tmp->num--;
		bool P=(p>>(29-i))%2;
		tmp=(tmp->son)[P];
	}
	tmp->num--;
}
int main(){
	ll q;cin>>q;
	REP(i,q){
		ll t,p,l;cin>>t;
		if(t==1){
			cin>>p;
			Save(p);
		}
		if(t==2){
			cin>>p;
			Del(p);
		}
		if(t==3){
			cin>>p>>l;
			cout<<Count(p,l)<<endl;
		}
	}
	return 0;
}