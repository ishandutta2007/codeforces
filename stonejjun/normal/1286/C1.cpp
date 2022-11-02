#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);
ll mod=998244353;
ll arr[1010101];
ll lst[1010101];
ll chk[1010101];
ll dp[3030][3030];
ll lf[101010];

ll n,m;
ll inf=1e18;
ll mval;
string s;
vector<string> sa[1010];
vector<string> sb[1010];
char ans[10101];
ll cnt[1010101];
ll ncnt[1010101];

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll t,T;

    ll i,j,k,l;
//    ll chk=0,cnt=0,val;
    ll a=0,b=0,c=0,d=0,x=0;
    ll e,f,g,h;
    ll cnta=0,cntb=0;
    ll lawin=0;
    //ll ans=1;

    cin>>n;
    cout<<"? 1 1"<<endl;
    cin>>s;
    if(n==1){
        cout<<"! "<<s<<endl;
        return 0;
    }
    ans[1]=s[0];
    cnt[ans[1]-'a']++;

    cout<<"? 1 "<<n<<endl;
    for(i=1;i<=n*(n+1)/2;i++){
        cin>>s;
        sort(s.begin(), s.end());
        sa[s.size()].pb(s);
    }
    cout<<"? 2 "<<n<<endl;
    for(i=1;i<=n*(n-1)/2;i++){
        cin>>s;
        sort(s.begin(), s.end());
        sb[s.size()].pb(s);
    }

    for(i=1;i<=n;i++){
        sort(sa[i].begin(), sa[i].end());
        sort(sb[i].begin(), sb[i].end());
    }

    for(i=2;i<=n;i++){
        string k;
        for(j=0;j<sa[i].size();j++){
            if(j==sb[i].size()||sa[i][j]!=sb[i][j]){
                k=sa[i][j];
                break;
            }
        }

       // cout<<i<<' '<<k<<'\n';
        for(j=0;j<=30;j++)
            ncnt[j]=cnt[j];

        for(j=0;j<i;j++){
            if(ncnt[k[j]-'a']==0){
               // cout<<j<<' '<<k[j]<<'\n';
                ans[i]=k[j];
                cnt[k[j]-'a']++;
                break;
            }
            ncnt[k[j]-'a']--;
        }
    }

    string fi;
    for(i=1;i<=n;i++)
        fi+=ans[i];
    cout<<"! "<<fi<<endl;
    return 0;

    
}