#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <cstring>

#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <vector>

using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}

struct result{
    int finish;
    int sleep;
    result(){
        finish = 1e8;
        sleep = -1e8;
    }
    result(int f,int s){
        //cerr<<"construct"<<f<<' '<<s<<endl;
        finish = f;
        sleep = s;
    }
    bool better_finish_than(const result& b) const {
        return finish < b.finish || (finish == b.finish && sleep > b.sleep);
    }
    bool better_sleep_than(const result& b) const {
        return sleep > b.sleep || (sleep == b.sleep && finish < b.finish);
    }
};

struct query{
    int start;
    int duration;
};
result byend[4002][4002];
result bysleep[4002][4002];
query q[4002];

void apply_res(result res, int cnt, int skipped){
    if(res.better_finish_than(byend[cnt][skipped]))
        byend[cnt][skipped] = res;
    if(res.better_sleep_than(bysleep[cnt][skipped]))
        bysleep[cnt][skipped] = res;
}
inline result get_res(const result& prev_res,const query& call){
    
    return result(max(call.start,prev_res.finish) + call.duration, max(prev_res.sleep,call.start - prev_res.finish));
}

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>q[i].start>>q[i].duration;
        --q[i].start;
    }
    apply_res(result(0,0), 0, 0);
    for(int i=1;i<=n;++i){
        for(int j=0;j<=min(k,n);++j){
        
        
            if(j>0){
                byend[i][j] = byend[i-1][j-1];
                bysleep[i][j] = bysleep[i-1][j-1];
            }
            //result tmp = get_res(byend[i - 1][j], q[i - 1]);
            apply_res(get_res(byend[i - 1][j], q[i - 1]),i,j);
            apply_res(get_res(bysleep[i - 1][j], q[i - 1]), i ,j);
            //cout<<"i,j="<<i<<' '<<j<<endl;
            //cout<<"byend="<<byend[i][j].sleep<<' '<<byend[i][j].finish<<endl;
            //cout<<"bysleep="<<bysleep[i][j].sleep<<' '<<bysleep[i][j].finish<<endl;
        }
        
    }
    int ans = 0;
    
    for(int i=0;i<=k;++i){
        ans = max(ans, max(bysleep[n][i].sleep, 86400-byend[n][i].finish));
    }
    cout<<ans;
}