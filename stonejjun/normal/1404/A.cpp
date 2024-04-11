#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define ss second 
#define ff first
#define pb push_back

string s;

ll arr[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll i,j,k,l,m,n;
        cin>>n>>m;
        cin>>s;
        ll chk=1;
        ll cnt1=0,cnt0=0;
        for(i=0;i<m;i++){
            if(s[i]=='0'){
                cnt0++;
                arr[i]=0;
            }
            else if(s[i]=='1'){
                cnt1++;
                arr[i]=1;
            }
            else{
                arr[i]=99;
            }
        }
        if(cnt0>m/2||cnt1>m/2) chk=0;
        for(i=m;i<n;i++){
            if(s[i]=='0'){
                cnt0++;
                if(arr[i%m]==1) chk=0;
                arr[i%m]=0;
            }
            else if(s[i]=='1'){
                cnt1++;
                if(arr[i%m]==0) chk=0;
                arr[i%m]=1;
            }
            if(s[i-m]=='0'){
                cnt0--;            }
            else if(s[i-m]=='1'){
                cnt1--;
            }
            if(cnt0>m/2||cnt1>m/2) chk=0;
        }
        cnt1=0;
        cnt0=0;
        for(i=0;i<m;i++){
            if(arr[i]==0) cnt0++;
            if(arr[i]==1) cnt1++;
        }
            if(cnt0>m/2||cnt1>m/2) chk=0;
        
        if(chk) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

}