#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll>pii;
#define ff first
#define ss second
#define pb push_back
ll arr[1010101];
ll ne[2][1010101];
ll vis[1010101];

vector<ll> v1;
vector<ll> v2;
ll nn;
ll ans[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,l,m,n;
    cin>>n;
    ll fl=1;

    for(i=2;i<=n;i++){
        ll a,b;
        cout<<"? "<<fl<<' '<<i<<endl;
        cin>>a;
        cout<<"? "<<i<<' '<<fl<<endl;
        cin>>b;
        if(a>b){
            ans[fl]=a;
            fl=i;
        } 
        else{
            ans[i]=b;
        }
    }
    ans[fl]=n;
    cout<<'!';
    for(i=1;i<=n;i++){
        cout<<' '<<ans[i];
    }
    cout<<endl;
    return 0;

}