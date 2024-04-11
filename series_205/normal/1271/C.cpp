#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n,sx,sy;
ll x,y,cnt[4];

int main(){
    cin>>n>>sx>>sy;
    rep(i,n){
        cin>>x>>y;
        if(x<sx)cnt[0]++;
        if(x>sx)cnt[1]++;
        if(y<sy)cnt[2]++;
        if(y>sy)cnt[3]++;
    }
    
    int ans=0;
    rep(i,4)if(cnt[ans]<cnt[i])ans=i;

    cout<<cnt[ans]<<endl;
    if(ans==0)sx--;
    if(ans==1)sx++;
    if(ans==2)sy--;
    if(ans==3)sy++;
    cout<<sx<<" "<<sy<<endl;
}