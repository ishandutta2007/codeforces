#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL x0,y0,ax,ay,bx,by;
LL xs,ys,t;
vector< pair<LL,LL> > v;
int main() {
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;

    v.push_back(make_pair(x0,y0));
    while(1) {
        LL x=v.back().first, y=v.back().second;
        LL nx = ax * x + bx;
        LL ny = ay * y + by; 
        if (ax >= (2e16 - bx + x - 1) / x) break;
        if (ay >= (2e16 - by + y - 1) / y) break;
        v.push_back(make_pair(nx, ny));
    }
    LL ans=0;
    for(int i=0;i<v.size();i++) {
        LL tmp=abs(xs-v[i].first)+abs(ys-v[i].second),val=0;
        if(tmp<=t) ++val,ans=max(ans,val);
        else continue;

        for(int j=i-1;j>=0;j--){
            tmp+=abs(v[j+1].first-v[j].first)+abs(v[j+1].second-v[j].second); 
            if(tmp<=t)++val,ans=max(ans,val);
            else break;
        }

        tmp+=abs(v[i].first-v[0].first)+abs(v[i].second-v[0].second);
        if(tmp>t) continue;
        for(int j=i+1;j<v.size();j++){
            tmp+=abs(v[j].first-v[j-1].first)+abs(v[j].second-v[j-1].second); 
            if(tmp<=t)++val,ans=max(ans,val);
            else break;
        }
    }
    cout<<ans<<endl;
}