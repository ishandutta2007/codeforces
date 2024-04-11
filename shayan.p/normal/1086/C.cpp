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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

set<int>ok,ok2;
vector<int>f,f2;
string S,A,B;
vector<int>s,a,b;
int n;

void choose(int a,int b){
    f[a]=b;
    ok.erase(b);
}
void print(){
    for(int i=0;i<sz(f);i++)
	cout<<char(f[i]+'a');
    cout<<"\n";
}
void do_rest(){
    for(int i=0;i<sz(f);i++){
	if(f[i]==-1)
	    choose(i,*ok.begin());
    }
}
void Begin(int k){
    ok.clear();f.clear();a.clear();b.clear();s.clear();
    f.resize(k,-1);
    n=sz(S);
    for(int i=0;i<k;i++)
	ok.insert(i);
    for(int i=0;i<n;i++)
	a.PB(A[i]-'a'),b.PB(B[i]-'a'),s.PB(S[i]-'a');
}
bool solvea(int pos){
    for(;pos<n;++pos){
	if(f[s[pos]]!=-1){
	    if(f[s[pos]]<a[pos]) return 0;
	    else if(f[s[pos]]>a[pos]) break;
	}
	else{
	    if(*ok.rbegin()>a[pos]){ choose(s[pos],*ok.rbegin());break;}
	    else if(*ok.rbegin()<a[pos]) return 0;
	    else choose(s[pos],a[pos]);
	}
    }
    return 1;
}
bool solveb(int pos){
    for(;pos<n;++pos){
	if(f[s[pos]]!=-1){
	    if(f[s[pos]]>b[pos]) return 0;
	    else if(f[s[pos]]<b[pos]) break;
	}
	else{
	    if(*ok.begin()<b[pos]){ choose(s[pos],*ok.begin());break;}
	    else if(*ok.begin()>b[pos]) return 0;
	    else choose(s[pos],b[pos]);
	}
    }
    return 1;
}
bool solve(){
    int pos=0;
    bool bl1=0,bl2=0;
    for(;pos<n && ((!bl1 && !bl2 && a[pos]==b[pos]) || f[s[pos]]!=-1);pos++){
	if(f[s[pos]]!=-1){
	    if((!bl1 && f[s[pos]]<a[pos]) || (!bl2 && f[s[pos]]>b[pos]))
		return 0;
	}
	else if(!ok.count(a[pos])){
	    return 0;
	}
	else{
	    choose(s[pos],a[pos]);
	}
	bl1|=(f[s[pos]]>a[pos]);
	bl2|=(f[s[pos]]<b[pos]);
    }
    if(pos==n || (bl1 && bl2))
	return 1;
    if(bl1)
	return solveb(pos);
    if(bl2)
	return solvea(pos);
    auto it1=ok.lower_bound(a[pos]),it2=ok.upper_bound(b[pos]);
    if(it1==it2)
	return 0;
    while(it1!=it2){
	if((*it1)!=a[pos] && (*it1)!=b[pos]){
	    choose(s[pos],*it1);
	    return 1;
	}
	it1++;
    }
    if(ok.find(a[pos])!=ok.end()){
	f2=f;ok2=ok;
	choose(s[pos],a[pos]);
	if(solvea(pos+1))
	    return 1;
	f=f2;ok=ok2;
    }
    if(ok.find(b[pos])!=ok.end()){
	f2=f;ok2=ok;
	choose(s[pos],b[pos]);
	if(solveb(pos+1))
	    return 1;
	f=f2;ok=ok2;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	int k;cin>>k;
	cin>>S>>A>>B;
	Begin(k);
	if(solve()){
	    cout<<"YES\n";
	    do_rest();
	    print();
	}
	else{
	    cout<<"NO\n";
	}
    }
}