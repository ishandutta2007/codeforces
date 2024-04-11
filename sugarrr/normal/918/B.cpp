
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
typedef pair<double,double>d_d;
#define inf 100000000//10^8

/////////////////////////////////




int main(){
    int n,m;cin>>n>>m;
    char s[n+1][11];
     int ss[n+1][5];
    for(int i=0;i<=n-1;i++)for(int j=0;j<=4;j++)ss[i][j]=0;
    for(int i=0;i<=n-1;i++){
        char gomi[30];
        cin>>s[i]>>gomi;
        int len=strlen(gomi);
        vector<int> v;
        for(int j=0;j<=len-1;j++){
            if(gomi[j]=='.')v.push_back(j);
        }

        int digit=v[0];int pow10=1;
            for(int j=v[0]-1;j>=0;j--){
                ss[i][0]+=(int)(gomi[j]-'0')*pow10;
                pow10*=10;
            }
        digit=v[1]-v[0]-1;pow10=1;
        for(int j=v[1]-1;j>v[0];j--){
            ss[i][1]+=(int)(gomi[j]-'0')*pow10;
            pow10*=10;
        }
        digit=v[2]-v[1]-1;pow10=1;
        for(int j=v[2]-1;j>v[1];j--){
            ss[i][2]+=(int)(gomi[j]-'0')*pow10;
            pow10*=10;
        }
        digit=len-1-v[2];pow10=1;
        for(int j=len-1;j>v[2];j--){
            ss[i][3]+=(int)(gomi[j]-'0')*pow10;
            pow10*=10;
        }
    }
    while(m--){
        char t[11];cin>>t;
        char tt[30];cin>>tt;
        int ans[5];for(int i=0;i<=3;i++)ans[i]=0;
        
        int tlen=strlen(tt);
        tlen--;
        vector<int> v;
        for(int j=0;j<=tlen-1;j++){
            if(tt[j]=='.')v.push_back(j);
        }
        
        int digit=v[0];int pow10=1;
        for(int j=v[0]-1;j>=0;j--){
            ans[0]+=(int)(tt[j]-'0')*pow10;
            pow10*=10;
        }
        digit=v[1]-v[0]-1;pow10=1;
        for(int j=v[1]-1;j>v[0];j--){
            ans[1]+=(int)(tt[j]-'0')*pow10;
            pow10*=10;
        }
        digit=v[2]-v[1]-1;pow10=1;
        for(int j=v[2]-1;j>v[1];j--){
            ans[2]+=(int)(tt[j]-'0')*pow10;
            pow10*=10;
        }
        digit=tlen-1-v[2];pow10=1;
        for(int j=tlen-1;j>v[2];j--){
            ans[3]+=(int)(tt[j]-'0')*pow10;
            pow10*=10;
        }
        
        int q=0;
        while(1){
            if(ans[0]==ss[q][0]&&ans[1]==ss[q][1]&&ans[2]==ss[q][2]&&ans[3]==ss[q][3]){
                cout<<t<<" "<<ans[0]<<"."<<ans[1]<<"."<<ans[2]<<"."<<ans[3]<<"; #"<<s[q]<<endl;
                break;
            }
            q++;
        }
        
    }
    return 0;
}