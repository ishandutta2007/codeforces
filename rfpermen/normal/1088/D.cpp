#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl "\n"
const int MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int a,b,ls,st;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout<<"? "<<a<<' '<<b<<endl;
    cin>>ls;
    rap(i,29,0){
    	if(!ls){
    		cout<<"? "<<(a|(1<<i))<<' '<<b<<endl;
    		cin>>st;
    		if(st==-1)a|=(1<<i), b|=(1<<i);
    		continue;
		}
    	cout<<"? "<<(a|(1<<i))<<' '<<(b|(1<<i))<<endl;
    	cin>>st;
    	if(st!=ls){
    		if(ls==1)a|=(1<<i);
    		else b|=(1<<i);
    		if(i==0)break;
    		cout<<"? "<<a<<' '<<b<<endl;
    		cin>>ls;
		}
		else {
    		cout<<"? "<<(a|(1<<i))<<' '<<b<<endl;
    		cin>>st;
    		if(st==-1)a|=(1<<i), b|=(1<<i);
		}
	}
	cout<<"! "<<a<<' '<<b<<endl;
    return 0;
}