// 1929
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,m;LL x[N],y[N];
vector< pair<double,double> > vec;
int nex[N][20];
bool ok(double d) {
    vec.clear();
    for(int i=1;i<=n;i++){
        double ang=atan2(y[i],x[i]);
        double det=acos(1.0*d/sqrt(x[i]*x[i]+y[i]*y[i]));
        vec.push_back(make_pair(ang+det,ang-det));
        vec.push_back(make_pair(ang+det+2*acos(-1),ang-det+2*acos(-1)));
    }
    sort(vec.begin(),vec.end());
    set< pair<int,double> > st;
    for(int i=0;i<vec.size();i++) st.insert(make_pair(i, vec[i].second));
    for(int i=0;i<vec.size();i++){  
        while(st.size()){
            pair<int,double> tmp = *st.begin();
            if(tmp.second < vec[i].first) st.erase(tmp);
            else {
                nex[i][0]=tmp.first; break;
            }
        }
        // printf("(%.6f, %.6f)\n", vec[i].first,vec[i].second);
        if(st.size()==0) nex[i][0]=i;
        //printf("i=%d, nex=%d\n", i,nex[i][0]);
    }
    for(int j=1;j<20;j++)for(int i=0;i<vec.size();i++) nex[i][j]=nex[nex[i][j-1]][j-1];
    for(int i=0;i<vec.size();i++){
        int now=i; 
        for(int j=19;j>=0;j--){
            if(m>>j&1) now=nex[now][j];
        }
        //printf("i=%d,now=%d\n", i,now);
        if(now-i>n-1) return 1; 
    }
    return 0;
}
int main() {
    scanf("%d%d",&n,&m);
    double r=1e18,l=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        r=min(r,sqrt(1LL*x[i]*x[i]+1LL*y[i]*y[i]));
    }
    //cout<<ok(1); return 0;
    for(int i=1;i<=50;i++){
        double mid=(l+r)/2;
        if(ok(mid)) l=mid;
        else r=mid;
    }
    printf("%.9f\n", l);
}