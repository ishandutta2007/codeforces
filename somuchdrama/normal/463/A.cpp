#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;
typedef long double LD;

#define pb push_back
#define cinn int n;cin>>n;
#define cinnm int n,m;cin>>n>>m;
#define cinnk int n,k;cin>>n>>k
#define ret return 0;
#define vc vector
#define forin for(int i=0;i<n;++i)


int main(){
    int ans = -1;
    cinnm
    forin{
        int t1, t2;
        cin >> t1 >> t2;
        if(100 * m >= 100 * t1 + t2){
            if(t2 == 0) t2 = 100;
            ans = max(ans, 100 - t2);
        }
    }
    cout << ans;
    ret
}