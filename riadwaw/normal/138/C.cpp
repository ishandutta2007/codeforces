#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
//map<char,int> m;
int l,r;


struct tree{
    int x;
    int h;
    int pl,pr;
    void scan(){
        cin>>x>>h>>pl>>pr;
    }
};

struct inttree{
    static const int shift = 1<<19;
    double a[2*shift];
    inttree(){
        std::fill(a,a+2*shift,1.0);
    }
    void set(int l, int r,double p){
        if(l>r)
            return ;
        if(l%2){
            a[l]*=p;
            return set(l+1,r,p);
        }
        if(r%2==0){
            a[r]*=p;
            return set(l,r-1,p);
        }
        return set(l/2,r/2,p);
    }

    double get(int x){
        if(!x)
            return 1;
        return a[x]*get(x/2);
    }
};
inttree it;
vector<int> xs;
inline int find(int x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
}
void solve() {
    int n,m,a[10101],b[10101];
    cin>>n>>m;
    tree t[101010];
    
    for(int i=0;i<n;++i){
        t[i].scan();
        xs.pb(t[i].x - t[i].h);
        xs.pb(t[i].x - 1);
        xs.pb(t[i].x + t[i].h);
        xs.pb(t[i].x + 1);
    }

    for(int j=0;j<m;++j){
        cin>>a[j]>>b[j];
        xs.pb(a[j]);
    }

    sort(xs.begin(),xs.end());
    xs.resize(unique(xs.begin(),xs.end())-xs.begin());

    


    for(int i=0;i<n;++i){
        it.set(find(t[i].x - t[i].h)+inttree::shift , find(t[i].x - 1)+inttree::shift, 1-t[i].pl/100.0);
        it.set(find(t[i].x + 1)+inttree::shift , find(t[i].x + t[i].h)+inttree::shift, 1-t[i].pr/100.0);
    }
    double ans = 0;
    for(int i=0;i<m;++i){
        ans+=it.get(find(a[i])+inttree::shift) * b[i];
    }
    printf("%.10lf\n",ans);
}