#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int N = 300000 + 10;
int T,n,a[N],k;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    vector<int> v;
    for(int i=2;i<=n;i++) v.push_back(a[i]-a[i-1]);
    sort(v.begin(),v.end());
    int ans = a[n] - a[1];
    for(int i=(int)v.size()-1;i>=(int)v.size()-(k-1);i--) ans -= v[i];
    cout<<ans<<endl;
}