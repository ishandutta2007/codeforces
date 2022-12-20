// Phoenix

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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int what(char ch){
    if(ch=='R') return 2;
    if(ch=='P') return 1;
    return 0;
}

int a[maxn],n;

struct fenwick{
    int sm[maxn];
    fenwick(){
	memset(sm,0,sizeof sm);
    }
    void add(int pos,int x){
	pos+=4;
	while(pos<maxn)
	    sm[pos]+=x,pos+=(pos & -pos);
    }
    int ask(int pos){
	pos+=4;
	int ans=0;
	while(pos>0)
	    ans+=sm[pos],pos-=(pos & -pos);
	return ans;
    }
    int ask(int r,int l){
	if(r<l) return 0;
	return ask(r)-ask(l);
    }
};fenwick fn[3];
set<int> st[3];

int solve(int nw){
    int gd=(nw+1)%3,bd=(nw+2)%3;
    int lg=n,rg=-1;
    if(!st[gd].empty()){
	lg=*st[gd].begin();
	rg=*st[gd].rbegin();
    }
    else if(st[bd].empty()){
	return 0;
    }
    else{
	return fn[nw].ask(n-1);
    }
    int lb=n,rb=-1;
    if(!st[bd].empty()){
	lb=*st[bd].begin();
	rb=*st[bd].rbegin();
    }
    int ans=0;
    if(rb>rg) ans+=fn[nw].ask(rb,rg);
    if(lg>lb) ans+=fn[nw].ask(lg,lb);
    return ans;
}

void change(int pos,int nw){
    int bf=a[pos];
    st[bf].erase(pos);
    fn[bf].add(pos,-1);
    st[nw].insert(pos);
    fn[nw].add(pos,1);
    a[pos]=nw;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>n>>q;
    string s;cin>>s;
    for(int i=0;i<n;i++)
	a[i]=what(s[i]),st[a[i]].insert(i),fn[a[i]].add(i,1);
    while(q--){
	cout<<n-solve(0)-solve(1)-solve(2)<<"\n";
	int pos;char ch;cin>>pos>>ch;
	change(--pos,what(ch));
    }
    cout<<n-solve(0)-solve(1)-solve(2)<<"\n";
    return 0;
}