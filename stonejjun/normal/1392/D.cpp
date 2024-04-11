#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back

ll dp[402020][10];
string s;
string s2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll i,j,k,l,m,n;
        cin>>n;
        s=s2;
        cin>>s;
        s+=s;
        ll chk=-1;
        for(i=0;i<n;i++)
            if(s[i]=='R'){
                chk=i;
                break;
            }
        if(chk==-1){
            cout<<(n+2)/3<<'\n';
            continue;
        }

        for(i=0;i<n;i++)
            for(j=0;j<6;j++)  
                dp[i][j]=1e18;  

        ll ans=1e18;

        if(s[chk]=='R') dp[0][0]=0;
        else dp[0][0]=1;

        for(i=1;i<n;i++){
            //printf("%lld %lld %lld\n",i,n,chk);
            if(s[i+chk]=='R'){
                dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
                dp[i][1]=dp[i-1][0];
                dp[i][2]=dp[i-1][0]+1;
                dp[i][3]=dp[i-1][2]+1;
                dp[i][4]=dp[i-1][1]+1;
                dp[i][5]=dp[i-1][4]+1;
            }
            else{
                dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]})+1;
                dp[i][1]=dp[i-1][0]+1;
                dp[i][2]=dp[i-1][0];
                dp[i][3]=dp[i-1][2];
                dp[i][4]=dp[i-1][1];
                dp[i][5]=dp[i-1][4];
            }
        }

        ans=min({ans,dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});


        for(i=0;i<n;i++)
            for(j=0;j<6;j++)  
                dp[i][j]=1e18;     
        if(chk!=n-1){
            chk++;

            if(s[chk]=='R') dp[0][0]=0;
            else dp[0][0]=1;

            for(i=1;i<n;i++){
                if(s[i+chk]=='R'){
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
                    dp[i][1]=dp[i-1][0];
                    dp[i][2]=dp[i-1][0]+1;
                    dp[i][3]=dp[i-1][2]+1;
                    dp[i][4]=dp[i-1][1]+1;
                    dp[i][5]=dp[i-1][4]+1;
                }
                else{
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]})+1;
                    dp[i][1]=dp[i-1][0]+1;
                    dp[i][2]=dp[i-1][0];
                    dp[i][3]=dp[i-1][2];
                    dp[i][4]=dp[i-1][1];
                    dp[i][5]=dp[i-1][4];
                }
            }

            ans=min({ans,dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
        }
        if(chk!=n-1){
            chk++;

            if(s[chk]=='R') dp[0][0]=0;
            else dp[0][0]=1;

            for(i=1;i<n;i++){
                if(s[i+chk]=='R'){
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
                    dp[i][1]=dp[i-1][0];
                    dp[i][2]=dp[i-1][0]+1;
                    dp[i][3]=dp[i-1][2]+1;
                    dp[i][4]=dp[i-1][1]+1;
                    dp[i][5]=dp[i-1][4]+1;
                }
                else{
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]})+1;
                    dp[i][1]=dp[i-1][0]+1;
                    dp[i][2]=dp[i-1][0];
                    dp[i][3]=dp[i-1][2];
                    dp[i][4]=dp[i-1][1];
                    dp[i][5]=dp[i-1][4];
                }
            }

            ans=min({ans,dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
        }
        if(chk!=n-1){
            chk++;

            if(s[chk]=='R') dp[0][0]=0;
            else dp[0][0]=1;

            for(i=1;i<n;i++){
                if(s[i+chk]=='R'){
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
                    dp[i][1]=dp[i-1][0];
                    dp[i][2]=dp[i-1][0]+1;
                    dp[i][3]=dp[i-1][2]+1;
                    dp[i][4]=dp[i-1][1]+1;
                    dp[i][5]=dp[i-1][4]+1;
                }
                else{
                    dp[i][0]=min({dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]})+1;
                    dp[i][1]=dp[i-1][0]+1;
                    dp[i][2]=dp[i-1][0];
                    dp[i][3]=dp[i-1][2];
                    dp[i][4]=dp[i-1][1];
                    dp[i][5]=dp[i-1][4];
                }
            }

            ans=min({ans,dp[i-1][2],dp[i-1][3],dp[i-1][4],dp[i-1][5]});
        }


         

        cout<<ans<<'\n';
    }
}