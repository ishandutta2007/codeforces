#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,k; set<int> st;
vector<int> ans;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x); st.insert(x);
    }
    int pre=0;
    for(auto x: st) {
        ans.push_back(x-pre); pre=x;
    }
    while(ans.size()<k) {
        ans.push_back(0);
    }
    for(int i=0;i<k;i++){
        printf("%d\n", ans[i]);
    }
}