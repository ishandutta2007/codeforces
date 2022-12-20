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

const int maxn=310,mod=1e9+7;
const ll inf=1e18;

int n,t,bef,nw;
bool ans[maxn];

void ask(int l,int r){
    bef=nw;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>nw;
    if(nw==-1){
	while(1){}
    }
}

void Make(int pos){
    if(pos==1 && (n&1)){
	ask(1,n);
	bool A=0,B=0;
	while(A!=0 || B!=1){
	    ask(2,3);
	    if((bef^nw)&1) A^=1;
	    else B^=1;
	}	
    }
    else{
	int pos1=(n&1?(pos-1):pos),pos2=pos;
	bool A=0,B=0;
	while(A!=1 || B!=0){
	    ask(pos1,pos2);
	    if(((bef^nw)&1)==(pos2&1)) A^=1;
	    else B^=1;
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>t;
    bef=nw=t;
    if(n==1){
	cout<<"! "<<(t==1?1:0)<<endl;
	return 0;
    }
    for(int i=1;i<=n;i++){
	Make(i);
	if(i>1) Make(i-1);
	ans[i]=((t-nw)==1);
	Make(i);
	if(i>1) Make(i-1);
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)
	cout<<ans[i];
    cout<<endl;
}