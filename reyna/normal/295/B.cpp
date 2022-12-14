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

const int Maxn = 5e2+20;
ll arr[Maxn][Maxn];
int X[Maxn];
ll ans[Maxn];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n;i++){
        cin >> X[i];
        X[i]--;
    }
    for(int k = n-1; k >= 0;k--){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                arr[i][j] = min(arr[i][X[k]]+arr[X[k]][j],arr[i][j]);
            }
        }
        for(int i = n-1; i >= k; i--){
            for(int j = n-1; j>=k;j--){
                ans[k]+=arr[X[i]][X[j]];
            }
        }
    }
    for(int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}