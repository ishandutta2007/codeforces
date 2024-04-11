#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int a,b;
set<int> st;
bool chk(int x,int remx,int y,int remy,int lef,int rig) {
    printf("solve %d %d %d %d [%d,%d]\n", x,remx,y,remy,lef,rig);
    if (remx < 0 || remy < 0 || remx > x || remy > y) return 0;
    if(x==0 || y==0) return 0;
    if(x+y<lef||x+y>rig) return 0;
    st.insert(x+y);
    return 1;
}
vector<int> v;
vector< pair<int,int> > seg;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int main() {
    cin>>a>>b;
    if(a==0 || b==0) {
        return !printf("1\n");
    }
    int n=a+b;
    LL nex,res=0; 
    for (LL i = 1; i <= n; i = nex + 1) {
        nex = n / (n / i);
        LL k = n / i;
        LL lx = (a+k)/(k+1), rx = a/k;
        LL ly = (b+k)/(k+1), ry = b/k;

        if(rx+ry>=lx+ly && lx<=rx && ly<=ry)
            seg.push_back(make_pair(rx+ry,lx+ly));     
    }
    sort(seg.begin(),seg.end());
    int lef = -1e9, ans = 0;
    for(int i=0;i<seg.size();i++){
        //printf("[%d, %d]\n", seg[i].second, seg[i].first);
        if(seg[i].second >= lef) {
            ans += seg[i].first - seg[i].second + 1; 
            lef = seg[i].first + 1;
        } else {
            ans += seg[i].first - lef + 1;
            lef = seg[i].first + 1;
        }
    }
    //printf("%d %d\n",ans,st.size());
    printf("%d\n", ans);
}