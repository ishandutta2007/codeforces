
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
#define inf 100000000/*10^8*/

/////////////////////////////////

ll po[1025];
ll kai[1005];
ll kai2[1005];
ll kkk(ll i,ll p){
    if(p==0)return 1;
    else if(p==1)return mod(i);
    else if(p%2==0)return mod(kkk(mod(mod(i)*mod(i)),p/2));
    else  return mod(mod(i)*mod(kkk(i,p-1)));
}
void calc(){
    po[0]=1;
    for(int i=1;i<=1023;i++){
        po[i]=mod(po[i-1]*2);
    }
    kai[0]=1;
    for(int i=1;i<=1001;i++){
        kai[i]=mod(kai[i-1]*i);
    }
    kai2[0]=1;
    for(int i=1;i<=1001;i++){
        kai2[i]=mod(mod(kai2[i-1])*mod(kkk(i,i_5)));
    }
}
int count(int m){
    int c=0;
    while(m>=1){
        if(m%2==1)c++;
        m=m/2;
    }
    return c;
}
ll comb(ll n,ll k){
    if(n==0){
        if(k==0)return 1;
        else return 0;
    }
    else if(n<k)return 0;
    else return mod(mod(mod(kai[n])*mod(kai2[n-k]))*mod(kai2[k]));
}

int main(){
    calc();
    char s[1005];cin>>s;
    ll n=0;ll len=strlen(s);
    int a[1025];a[1]=0;
    for(int i=2;i<=1023;i++){
        int cc=count(i);
        if(cc==1)a[i]=1;
        else a[i]=a[cc]+1;
    }
    ll ans=0;
    int k;cin>>k;
    
    if(len<=10){
        for(ll i=len-1;i>=0;i--){
            n+=((int)s[i]-'0')*po[len-i-1];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==k)ans++;
        }
        cout<<ans<<endl;
        return 0;
        
    }
    
    for(int i=1;i<=1023;i++){
        if(a[i]==k)ans++;
    }
    int cou=0;
    for(int i=0;i<=len-1;i++)if(s[i]=='1')cou++;
    if(a[cou]==k-1)ans++;//n
    for(int i=1;i<=1023;i++){
        if(a[i]==k-1){

            ans+=mod(comb(len-1,i))-comb(10,i);
            ans=mod(ans);
            
            int kk=1,pos=1;
            while(pos<=len-1&&kk<=i){
                if(s[pos]=='1'){
                    ans+=comb(len-pos-1,i-kk);
                    kk++;
                    pos++;
                }else{
                    pos++;
                }
            }
            ans=mod(ans);
        }
    }
    cout<<mod(ans)<<endl;
    return 0;
}