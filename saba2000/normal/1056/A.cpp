#include<bits/stdc++.h>
using namespace std;
int f[1009];
main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            f[x]++;
        }
    }
    for(int i = 0; i <= 1000; i++)
        if(f[i] == n) cout << i << " ";
    cout<<endl;
}