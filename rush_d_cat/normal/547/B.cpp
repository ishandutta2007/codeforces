#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=2000000+10;
map<int, vector<int> > vec;
int n,a[N],ans[N];
set<int> st;
multiset<int> frag;
int main() {    
    scanf("%d",&n);
    //n=200000;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //a[i]=rand();
        vec[a[i]].push_back(i);
    }
    st.insert(0); st.insert(n+1); frag.insert(n);
    int res=1e9;
    for(auto p: vec) {
        int val = p.first;
        vector<int> v = p.second;
        res = min(res,*frag.rbegin());

        ans[res]=val;

        int tmp=0;
        for(auto x: v) {
            auto it = st.lower_bound(x);
            int r=*it; it--; int l=*it;
            frag.erase(frag.find(r-l-1));
            frag.insert(x-l-1);
            frag.insert(r-x-1);
            st.insert(x);    
        }
    }
    ans[n+1]=*min_element(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        if(ans[i]==0) {
            ans[i]=ans[i+1];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ", ans[i]);
}