#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long LL;
const int N=1000002;

int n,a[N],vis[N];
stack< pair<int,int> > stk;
vector<int> ans;
int main(){
    scanf("%d",&n);
    LL sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); vis[a[i]]=1;
    }
    for(int i=1;i<=500000;i++) {
        if(vis[i]==0 && vis[1000000+1-i]==0) {
            stk.push(make_pair(i,1000000+1-i));
        }
    }

    for(int i=1;i<=500000;i++){
        if(vis[i]==1 && vis[1000000+1-i]==1) {
            pair<int,int> p = stk.top(); stk.pop();
            ans.push_back(p.first); ans.push_back(p.second);
        } else if(vis[i]==1){
            ans.push_back(1000000+1-i);
        } else if(vis[1000000+1-i]==1){
            ans.push_back(i);
        }
    }
    printf("%d\n", ans.size());
    for(auto x: ans) printf("%d ", x);
}