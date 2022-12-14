#include <iostream>
using namespace std;
int ans[4001];
int main(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    ans[a] = 1;
    ans[b] = 1;
    ans[c] = 1;
    for(int i = 0; i <= n;i++){
        if(i >= a && ans[i-a] != 0){
            if(ans[i-a]+1 > ans[i]){
                ans[i] = ans[i-a]+1;
            }
        }
        if(i >= b && ans[i-b] != 0){
            if(ans[i-b]+1 > ans[i]){
                ans[i] = ans[i-b]+1;
            }
        }
        if(i >= c && ans[i-c] != 0){
            if(ans[i-c]+1 > ans[i]){
                ans[i] = ans[i-c]+1;
            }
        }
    }
    cout << ans[n];
}