#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
const ll MAX=100010;
const int MOD=1000000000 + 7;
const ll INF=1000000000000000000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1){
    	cout<<"1 1"<<endl<<1<<endl;
    	return 0;
	}
	else if(n==2){
		cout<<"2 2"<<endl<<"1 2"<<endl;
		return 0;
	}
	n--;
	cout<<n*2<<" 2"<<endl<<"1 2"<<endl;
    return 0;
}