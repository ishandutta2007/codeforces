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
const int MAX=100005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
int n;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n<3)cout<<1<<endl<<1<<endl;
    else if(n==3)cout<<2<<endl<<"1 3"<<endl;
    else if(n&1){
        cout<<n<<endl;
        for(int i=n;i>=1;i-=2)cout<<i<<" ";
        for(int i=n-1;i>=2;i-=2){
            cout<<i;
            if(i!=2)cout<<" ";
            else cout<<endl;
        }
    }
    else {
        cout<<n<<endl;
        for(int i=n-1;i>=1;i-=2)cout<<i<<" ";
        for(int i=n;i>=2;i-=2){
            cout<<i;
            if(i!=2)cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}