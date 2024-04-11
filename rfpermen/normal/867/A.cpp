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
const ll MAX=1000010;
const int MOD=1000000000 + 7;
const ll INF=1000000000000000000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n,cnt,cnt2;
char c,ls;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>ls;
    rep(i,2,n){
    	cin>>c;
    	if(c!=ls){
    		if(ls=='S')cnt++;
    		else cnt2++;
		}
		ls=c;
	}
	//cout<<cnt<<" "<<cnt2<<endl;
	if(cnt>cnt2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    return 0;
}