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
    cinn
    vc<int> A(n, 0);
    vc<int> B(n, 0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int tt;
        cin >> tt;
        A[tt - 1] = 1;
    }
    cin >> t;
    for(int i = 0; i < t; ++i){
        int tt;
        cin >> tt;
        B[tt - 1] = 1;
    }
    string ans = "I become the guy.";
    forin{
        if(!(A[i] || B[i])){
            ans = "Oh, my keyboard!";
        }
    }
    cout << ans;
    ret
}