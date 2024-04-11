#include <iostream>
using namespace std;

int N, v[100005], f[100005], ans;

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> v[i];
        f[i] = 1;
        if(v[i] > v[i-1]) f[i] = f[i-1] + 1;
    }    

    for(int i=1; i<=N; i++){
        ans = max(ans, min(f[i]+1, N));
        if(v[i-f[i]+1] > v[i-f[i]-1] + 1)
            ans = max(ans, f[i] + f[i-f[i]]);        
        if(v[i-f[i]+2] > v[i-f[i]] + 1)
            ans = max(ans, f[i] + f[i-f[i]]);        
    }

    cout << ans << endl;
    return 0;
}