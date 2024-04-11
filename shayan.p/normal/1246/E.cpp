// Remember...

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

const int maxn=16, MASK=1<<16, MAX=2010;
			   
int a[maxn], in[maxn];
bitset<MAX> bs[MASK];

multiset<pii> st;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k; cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    
    bs[0][0]=1;
    for(int msk=1;msk<(1<<n);msk++){
	for(int i=0;i<n;i++){
	    if(bit(msk,i)){
		bs[msk]= bs[msk] | (bs[msk ^ (1<<i)] << a[i]);
	    }
	}
	for(int i=MAX-1;i>=0;i--){
	    if(i%k == 0 && bs[msk][i])
		bs[msk][i/k]=1;
	}
    }
    if(bs[(1<<n)-1][1]==0) return cout<<"NO\n",0;
    
    int msk=(1<<n)-1, num=1, dv=0;

    while(msk>0){//
	while(num<MAX){
	    for(int i=0;i<n;i++){
		if(bit(msk,i)){
		    if(num>=a[i] && bs[msk ^ (1<<i)][num - a[i]]){
			in[i]=dv;
			num-=a[i];
			msk^=1<<i;
			goto Hell;
		    }
		}
	    }
	    num*=k, dv++;
	}
    Hell:;
    }

    cout<<"YES\n";
    
    for(int i=0;i<n;i++){
	st.insert({in[i],a[i]});
    }
    while(sz(st)>1){
	pii A=*(--st.end());
	st.erase(st.find(A));
	pii B=*(--st.end());
	st.erase(st.find(B));
	assert(A.F==B.F);
	cout<<A.S<<" "<<B.S<<"\n";
	int sum=A.S + B.S, pos=A.F;
	while(sum % k==0) sum/=k, pos--;
	st.insert({pos,sum});
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")