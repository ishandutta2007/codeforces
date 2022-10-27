#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N],vis[N];
int main() {
    scanf("%d",&n);
    vector<int> v;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end()); v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(i==j) continue;
            if(v[j]%v[i]==0) vis[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++) {
        if(vis[i]==0) ans++;
    }
    printf("%d\n", ans);
}