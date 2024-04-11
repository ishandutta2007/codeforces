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

const int BITS=30;

int ask(int A,int B){
    cout<<"? "<<A<<" "<<B<<endl;
    int x;cin>>x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int A=0,B=0;
    int bef=ask(0,0);
    for(int i=BITS-1;i>=0;i--){
	int x=ask(A^(1<<i),B^(1<<i));
	if(bef==1){
	    if(x==bef){
		if(ask(A^(1<<i),B)==-1)
		    A^=(1<<i),B^=(1<<i);
	    }
	    else{
		A^=(1<<i);
		bef=ask(A,B);
	    }
	}
	else if(bef==0){
	    if(ask(A^(1<<i),B)==-1)
		A^=(1<<i),B^=(1<<i);
	}
	else if(bef==-1){
	    if(x==bef){
		if(ask(A^(1<<i),B)==-1)
		    A^=(1<<i),B^=(1<<i);
	    }
	    else{
		B^=(1<<i);
		bef=ask(A,B);
	    }
	}
    }
    cout<<"! "<<A<<" "<<B<<endl;
    return 0;
}