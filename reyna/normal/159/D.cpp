#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int Maxn = 2e3+10;
bool isPal[Maxn][Maxn];
int star[Maxn];
int end[Maxn];
int main(){
    string S;
    cin >> S;
    int n;
    n = S.length();
    for(int i = 0; i < n;i++){
        isPal[i][0] = true;
        star[i]++;
        end[i]++;
    }
    for(int i = 1;i<n;i++){
        if(S[i-1] == S[i]){
            isPal[i-1][1] = true;
            star[i-1]++;
            end[i]++;
        }
    }
    for(int j = 2;j < n;j++){
        for(int i = 0; i < n;i++){
            if(i+j>n-1)
                break;
            if(isPal[i+1][j-2] && S[i] == S[i+j]){
                isPal[i][j] = true;
                star[i]++;
                end[i+j]++;
            }
        }
    }
//  for(int i = 0; i < n;i++){
//      cout << star[i] << " " << end[i] << endl;
//  }
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < n;i++){
        ans+=cnt*star[i];
        cnt+=end[i];
    }
    cnt = 0;
    for(int i = n-1; i >= 0;i--){
        ans+=cnt*end[i];
        cnt+=star[i];
    }
    cout << ans/2 << endl;
    return 0;
}