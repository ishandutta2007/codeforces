#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back

ll fld[30][30];
ll mn[30][30];
ll mx[30][30];

int main(){
    ll n;
    cin>>n;
    ll i,j,k,l,m,t;
    for(i=0;i<=26;i++){
        fld[i][0]=(1<<i);
        mn[0][0]=mx[0][0]=1;
        if(i!=0) mn[i][0]=mx[i][0]=mn[i-1][0]+fld[i][0];
    }
    for(i=0;i<n;i++)
        for(j=1;j<n;j++){
            fld[i][j]=fld[i-1][j]+fld[i][j-1];
            if(i!=0) mn[i][j]=fld[i][j]+mn[i-1][j];
            else mn[i][j]=fld[i][j]+mn[i][j-1];
            mx[i][j]=fld[i][j]+mx[i][j-1];
            //printf("qwe %lld %lld %lld %lld %lld\n",i,j,fld[i][j],mn[i][j],mx[i][j]);
        }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<fld[i][j]<<' ';
        cout<<'\n';
    }

    cin>>t;
    while(t--){
        ll i,j,k,l,m;
        cin>>m;
        stack<pii> s;
        s.push({n,n});
        i=n-1;
        j=n-1;
        while((i+j)!=0){
          // printf("%lld %lld %lld %lld %lld\n",i,j,mn[i][j],mx[i][j],m);
           m-=fld[i][j];
            if(i==0) j--;
            else if(j==0) i--;
            else if(m<=mx[i-1][j]) i--;
            else j--;
            s.push({i+1,j+1});
        }
        while(s.size()){
            cout<<s.top().ff<<' '<<s.top().ss<<'\n';
            s.pop();
        }
        cout<<'\n';
    }
}