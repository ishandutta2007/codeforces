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

int n,t,a[N],dp[N],op[N],prv[N];
string s;
vector<int> vec[N];

void Main(){
	cin>>n>>s; s=' '+s; n<<=1;
	int b=0,id=0,fst=-1,lst=-1;
	f(i,1,n+1){
		a[i]=a[i-1]+(s[i]=='(' ? +1 : -1);
		if(a[i]<0){
			b=1;
			lst=i;
			if(fst==-1) fst=i;
		}
		if(a[i]>a[id]) id=i;
	}
	//dbga(a,0,n+1);
	if(b==0){
		cout<<0<<'\n';
		return ;
	}
	int id1=0,id2=0;
	f(i,0,fst){
		if(a[i]>=a[id1]){
			id1=i;
		}
	}
	f(i,lst+1,n+1){
		if(a[i]>=a[id2]){
			id2=i;
		}
	}
	//eror(lst);
//	eror(id2);
	reverse(s.begin()+id1+1,s.begin()+id2+1);
	//f(i,0,(id2-id1)/2) swap(s[id1+i+1],s[id2-i]);
	int sum=0,c=0;
	f(i,1,s.size()){
		if(s[i]=='(') sum++;
		else sum--;
		if(sum<0) c=1;
	}
	if(c==0){
		cout<<1<<'\n'<<id1+1<<" "<<id2<<'\n';
		return;
	}
	cout<<2<<'\n'<<1<<" "<<id<<'\n'<<id+1<<" "<<n<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
		f(i,0,n) vec[i].clear();
	}
}