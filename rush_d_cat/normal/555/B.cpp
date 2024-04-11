#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N=200000+10;

int n,m,res[N];
LL l[N],r[N]; pair<LL,int> a[N];
vector< pair<pair<LL,LL> ,int> > v;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&l[i],&r[i]);
    for(int i=2;i<=n;i++)
        v.push_back(make_pair(make_pair(r[i]-l[i-1], l[i]-r[i-1]),i));
    sort(v.begin(),v.end());
    for(int i=1;i<=m;i++) {
        scanf("%lld",&a[i].first); a[i].second=i;
    }
    sort(a+1,a+1+m);
    
    multiset< pair<LL,int> > R;
    for(int i=0,j=1;i<v.size();i++){
        while(j<=m && a[j].first<=v[i].first.first) {
            R.insert(a[j]); j++;
        }
        LL L=v[i].first.second;
        if(R.size()==0 || (R.rbegin())->first < L) return !printf("No\n");
        pair<LL,int> tmp = *R.lower_bound( make_pair(L,0) );
        R.erase(tmp);
        res[v[i].second] = tmp.second;
    }
    printf("Yes\n");
    for(int i=2;i<=n;i++)
        printf("%d ", res[i]);
}