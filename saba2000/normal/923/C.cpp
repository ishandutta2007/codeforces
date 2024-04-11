#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define ll long long 
#define pb push_back
//#define mp make_pair
#define fr first
#define sc second
#define MAX ((ll)(1e15+100))
#define ARRS ((ll)(1e6+100))
#define MOD ((ll)(1e9+7))
#define EP ((double)(1e-9))
#define EPS ((double)(1e-8))
#define pb push_back
#define PI ((double)3.141592653)

ll n,m,k,p,q,h;
ll d,b;
ll a[ARRS];
struct node {
	node * x[2];
	ll s;
	node(){
		x[0]=NULL;
		x[1]=NULL;
		s=0;
	}
	void updt(){
		s=0;
		if(x[0])s+=x[0]->s;
		if(x[1])s+=x[1]->s;
	}
};

node * root=NULL;
void add(ll i,ll a,node *& x){
	if(!x)x=new node();
	if(i==0){
		x->s++;
		return;
	}
	if(a&(1ll<<(i-1)))add(i-1,a,x->x[1]);
	else add(i-1,a,x->x[0]);
	x->updt();
}

ll pas=0;
void go(ll i,ll a,node *& x,ll t){
	if(i==0){
		x->s--;
		pas=a^t;
		return;
	}
	if(a&(1ll<<(i-1))){
		if(x->x[1]&&x->x[1]->s)
			go(i-1,a,x->x[1],t*2+1);
		else go(i-1,a,x->x[0],t*2);
	}
	else {
		if(x->x[0]&&x->x[0]->s)
			go(i-1,a,x->x[0],t*2);
		else go(i-1,a,x->x[1],t*2+1);
	}
	x->updt();
}


int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>k;
		add(34,k,root);
	}
	for(int i=0; i<n; i++){
		k=a[i];
		go(34,k,root,0);
		cout<<pas<<" ";
	}
}