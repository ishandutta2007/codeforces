#include <iostream>
#include <vector>
using namespace std;
int n,m;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main() {
    cin>>n>>m;
    if(m<n-1) {
        return !printf("Impossible\n");
    }
    int tot=0;
    vector< pair<int,int> > ans;
    for(int i=1;i<n;i++) {
        ans.push_back(make_pair(i,i+1)); tot ++;
    }
    for(int i=1;i<=n;i++){
        if(tot==m)break;
        for(int j=i+2;j<=n;j++){
            if(tot==m) break;
            if(gcd(i,j)==1){
                ans.push_back(make_pair(i,j));
                tot++;
            }
        }
    }
    if(ans.size()!=m) {
        return !printf("Impossible\n");
    }
    printf("Possible\n");
    for(int i=0;i<ans.size();i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}