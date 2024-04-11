#include <iostream>
#include <vector>
#include <algorithm>


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
    int c = 0;
    forin{
        int p, q;
        cin >> p >> q;
        if (q - p >=2){
            ++c;
        }
    }
    cout << c;

    ret
}