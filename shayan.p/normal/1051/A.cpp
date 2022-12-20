// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=110,mod=1e9+7;
const ll inf=1e18;

int arr[maxn];

int main(){
    int q;cin>>q;
    while(q--){
	string s;cin>>s;
	int n=sz(s);
	int A=0,B=0,C=0;
	FOR(i,0,n-1){
	    if('0'<=s[i] && s[i]<='9')
		A++,arr[i]=0;
	    else if('a'<=s[i] && s[i]<='z')
		B++,arr[i]=1;
	    else
		C++,arr[i]=2;
	}
	int x=(A>0)+(B>0)+(C>0);
	if(x==3){
	    cout<<s<<endl;
	}
	if(x==2){
	    char ch;
	    if(A==0){
		ch='0';
	    }
	    if(B==0){
		ch='a';
	    }
	    if(C==0){
		ch='A';
	    }
	    FOR(i,0,n-1){
		if('0'<=s[i] && s[i]<='9' && A>1){
		    s[i]=ch;
		    break;
		}
		if('a'<=s[i] && s[i]<='z' && B>1){
		    s[i]=ch;
		    break;
		}
		if('A'<=s[i] && s[i]<='Z' && C>1){
		    s[i]=ch;
		    break;
		}
	    }
	    cout<<s<<endl;
	}
	if(x==1){
	    if(A>0){
		s[0]='a';
		s[1]='A';
	    }
	    if(B>0){
		s[0]='0';
		s[1]='A';
	    }
	    if(C>0){
		s[0]='0';
		s[1]='a';
	    }
	    cout<<s<<endl;
	}
    }
}