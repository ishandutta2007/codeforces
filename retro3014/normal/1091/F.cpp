#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
#define MAX_N 100000
typedef long long ll;
 
int N;
ll l[MAX_N+1];
ll need[MAX_N+1];
int type[MAX_N+1];
string str;
 
ll ans=0;
 
int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%lld", &l[i]);
        l[i]*=2;
    }
    cin>>str;
    for(int i=0; i<N; i++){
        if(str[i]=='G') type[i+1]=1;
        else if(str[i]=='W')    type[i+1]=2;
        else type[i+1]=3;
    }
    need[N]=0;
    for(int i=N-1; i>=0; i--){
        if(type[i+1]==1 || type[i+1]==2){
            need[i] = max((ll)0, need[i+1]-l[i+1]);
        }else{
            need[i] = need[i+1]+l[i+1];
        }
    }
    ll s=0;
    bool water=false;
    for(int i=1; i<=N; i++){
        if(type[i]==1){
            s+=l[i];
            ans+=l[i]*5;
            if(s>need[i]){
                ll more = s-need[i];
                more/=2;
                more=min(more, l[i]);
                ans-=4*more;
                s-=2*more;
            }
        }else if(type[i]==2){
            water = true;
            s+=l[i];
            ans+=l[i]*3;
        }else{
            if(s<l[i]){
                ll more = l[i]-s;
                if(water){
                    ans+=more*3;
                    s+=more;
                }else{
                    ans+=more*5;
                    s+=more;
                }
            }
            s-=l[i];
            ans+=l[i];
        }
    }
    if(s>0){
        ans-=((s/2)*2);
    }
    printf("%lld", ans/2);
    return 0;
}