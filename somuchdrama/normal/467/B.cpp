#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, m,  k;
    cin >> n >> m >> k;
    vc<vc<bool> > A;
    vc<LL> pows(n);
    LL two = 1;
    forin{
        pows[i] = two;
        two *= 2;
    }

    for(int i = 0; i < m + 1; ++i){
        LL t;
        cin >> t;
        vc<bool> tv;
        for(int j = n - 1; j > -1; --j){
            if(t >= pows[j]){
                t -= pows[j];
                tv.pb(1);
            }else{
                tv.pb(0);
            }
        }
        A.pb(tv);
    }
    int gc = 0;
    for(int i = 0; i < m; ++i){
        int c = 0;
        for(int j = 0; j < n; ++j){
            if (A[i][j] != A[m][j]){
                ++c;
            }
        }
        if (c <= k){
            ++gc;
//            cout << i << ' ';
        }
    }

    cout << gc;
    ret
}