#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
map<LL, vector< pair<LL,LL> > > rmp,cmp,mp,mpcopy; 
map<LL, vector< pair<LL,LL> > >::iterator it;
set< vector< pair<LL,LL> >  > st;
LL gcd(LL x, LL y){
    return y==0?x:gcd(y,x%y);
}
void get_gcd(vector< pair<LL,LL> > &v) {
    LL g=v[0].second;
    for(int i=1;i<v.size();i++)
        g=gcd(g,v[i].second);
    for(int i=0;i<v.size();i++)
        v[i].second/=g;
}
LL ans=0;
void chk(LL g_) {
    LL tot = (mp.begin()->second)[0].second;
    LL len = tot / g_;
    for(it=mp.begin();it!=mp.end();it++) {
        if((it->second)[0].second % len)
            return;
    }
    ans ++;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        LL w,h,c;
        scanf("%lld%lld%lld",&w,&h,&c);
        rmp[w].push_back(make_pair(h, c));
        cmp[h].push_back(make_pair(w, c));
    }
    
    for(it=rmp.begin();it!=rmp.end();it++) {
        sort((it->second).begin(), (it->second).end());
    }
    for(it=cmp.begin();it!=cmp.end();it++) {
        sort((it->second).begin(), (it->second).end());        
    }
    mp = (rmp.size()<cmp.size())?rmp:cmp; mpcopy = mp;

    for(it=mpcopy.begin();it!=mpcopy.end();it++) {
        get_gcd(it->second);
        st.insert(it->second);
    }


    if (st.size() > 1) return !printf("0\n");
    


    vector< pair<LL,LL> > v = mp.begin() -> second;
    LL g=v[0].second;
    for(int i=1;i<v.size();i++)
        g=gcd(g,v[i].second);
    for(LL x=1;x*x<=g;x++) {
        if(g%x==0) {
            chk(x);
            if(x*x!=g) chk(g/x);
        }
    }
    printf("%lld\n", ans);
}