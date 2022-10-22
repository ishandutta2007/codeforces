#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,a[N],b[N],cnt[N];

void Main(){
	cin>>n;
	f(i,1,n+1) cnt[i]=0;
	f(i,1,n+1) cin>>a[i];
	f(i,1,n+1) cin>>b[i];
	vector<pair<int,int>> B;
	f(i,1,n+1){
		int p=i,cnt=1;
		while(b[p+1]==b[p]) p++,cnt++;
		B.pb({b[i],cnt});
		i=p;
	}
	f_(i,n,1){
		if(B.size() && a[i]==B.back().F){
			//eror(i);
			cnt[a[i]]+=B.back().S-1;
			B.pop_back();
		}
		else{
			cnt[a[i]]--;
			if(cnt[a[i]]<0){
				cout<<"NO"<<'\n';
				return ;
			}
		}
	}
	if(B.size()){
		cout<<"NO"<<'\n';
	}
	else{
		cout<<"YES"<<'\n';
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
5
1 2 3 3 2
1 3 3 2 2
*/