#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N];
int main() {
    scanf("%d",&n);
    int s1=0,s2=0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    s1+=a[1];ans.push_back(1);
    for(int i=2;i<=n;i++){
        if(a[1]>=2*a[i]){
            s1+=a[i];ans.push_back(i);
        }else{
            s2+=a[i];
        }
    }
    if(s1>s2){
        printf("%d\n", ans.size());
        for(auto x: ans) printf("%d ", x);
    } else {
        printf("0\n");
    }
}