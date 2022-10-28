#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);

using namespace std;



int main(){ sl
    int n,k;
    cin >> n >> k;
    int ans[n+1];
    bool hash[n+1];
    for(int i=1;i<=n;i++)
        hash[i] = false;

    for(int i=k+1;i<=n;i++){
        ans[i] = i;
        hash[i] = true;
    }

    ans[k] = 1;
    for(int i=k-1;i>=1;i--){
        if(ans[i+1]+i<=n && hash[ans[i+1]+i]==false){
            ans[i] = ans[i+1] + i;
            hash[ans[i+1]+i] = true;
        }
        else{
            ans[i] = ans[i+1] - i;
            hash[ans[i+1]-i] = true;
        }
    }

    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";


    return 0 ;
}