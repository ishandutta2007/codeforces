// Wanna Hack? GL...

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

const int maxn=1e5+10,lim=40;
const ll inf=2e18,Big=1e15;

ll dp[20][3];// = // A+ // B+

ll f(int a,int b,ll num){
    if(num<0) return -Big;
    ll ans=(num/2)*20;
    if(num&1){
	while(a<9 && b<9){
	    ans+=2;
	    a++,b++;
	}
	if(a==b) return ans+1;
	ans+=2;
	a=(a+1)%10,b=(b+1)%10;	
    }
    while(a<9 && b<9){
	ans+=2;
	a++,b++;
    }
    if(a==9) return ans;
    return ans+1;
}
ll g(int a,int b,string &str){
    ll ans=0;
    while(str[a]==str[b] && ans<lim){
	int A=(a+1)%10,B=(b+1)%10;
	if(str[A]!=str[b]) return ans;
	ans++;
	if(str[A]!=str[B]) return ans;
	ans++;
	a=A,b=B;
    }
    if(ans==lim) return inf;
    return ans;
}
ll f2(int a,int b,ll num){
    if(num<0) return -Big;
    ll ans=(num/2)*10;
    if(num&1){
	while(a<9 && b<9){
	    ans++;
	    a++,b++;
	}
	if(a==b) return ans;
	ans++;
	a=(a+1)%10,b=(b+1)%10;
    }
    while(a<9 && b<9){
	ans++;
	a++,b++;
    }
    return ans;
}
ll g2(int a,int b,string &str){
    ll ans=0;
    while(str[a]==str[b] && ans<lim){
	a=(a+1)%10,b=(b+1)%10;
	if(str[a]!=str[b]) break;
	ans++;
    }
    if(ans==lim) return  inf;
    return ans;
}
inline void smax(ll &a,ll b){
    if(a<b) a=b;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q;cin>>q;
    while(q--){
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<20;i++){
	    for(int j=0;j<3;j++)
		dp[i][j]=-Big;
	}
	dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;i++){
	    string str;cin>>str;
	    int pos1=s[i-1]-'0';
	    for(int pos2=0;pos2<10;pos2++){
		if(str[pos1]!=str[pos2]) continue;
		if(pos1==pos2){
		    smax(dp[i][0],dp[i-1][0]*10+9-pos1);
		    smax(dp[i][1],min(f(pos1,pos2,dp[i-1][1]),g(pos1,pos2,str)));
		    smax(dp[i][2],min(f(pos2,pos1,dp[i-1][2]),g(pos2,pos1,str)));
		}
		if(pos1<pos2){
		    smax(dp[i][0],min(f2(pos1,pos2,dp[i-1][2]),g2(pos1,pos2,str)));
		    smax(dp[i][1],min( f(pos1,pos2,dp[i-1][2]), g(pos1,pos2,str)));
		    smax(dp[i][2],min( f(pos2,pos1,dp[i-1][2]), g(pos2,pos1,str)));
		}
		if(pos2<pos1){
		    smax(dp[i][0],min(f2(pos1,pos2,dp[i-1][1]),g2(pos1,pos2,str)));
		    smax(dp[i][1],min( f(pos1,pos2,dp[i-1][1]), g(pos1,pos2,str)));
		    smax(dp[i][2],min( f(pos2,pos1,dp[i-1][1]), g(pos2,pos1,str)));
		}
		//	cout<<i<<" "<<pos2<<"   "<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
	    }
	}
	if(dp[n][0]<0) dp[n][0]=-1;
	cout<<dp[n][0]+1<<"\n";
    }
}