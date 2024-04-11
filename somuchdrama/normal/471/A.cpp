#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

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
    vc<int> A(6);
    vc<int> B(9, 0);
    int n = 6;
    for(int i = 0; i < 6; ++i){
    cin >> A[i];
    B[A[i] - 1]++;
    }
    string ans = "Alien";
    bool s = 0;
    for(int i = 0; i < 9; ++i){
        if(B[i] >= 4){
            B[i] -= 4;
            s = 1;
        }
    }
    if(s){
    ans = "Bear";
    for(int i = 0; i < 9; ++i){
        if(B[i] > 1){
            ans = "Elephant";}
    }}
    cout << ans;

    ret
}