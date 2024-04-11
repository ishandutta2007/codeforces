#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(short int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define endl "\n"
#define ot {st=0; break;}
const int dr[]={-1,1,0,0};
const int dc[]={0,0,1,-1};

ll t,x,y,n;

int main(){
    //cout<<fixed<<setprecision(3);
//  freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>x>>y>>n;
    	x = abs(x) , y = abs(y);
    	if(x<y)swap(x,y);
    	if(x>n){
    		cout<<"-1\n"; continue;
		}
		if((x-y)&1){
			cout<<n-1<<endl;
		}
		else {
			if((n-x)&1)cout<<n-2<<endl;
			else cout<<n<<endl;
		}
	}
    return 0;
}