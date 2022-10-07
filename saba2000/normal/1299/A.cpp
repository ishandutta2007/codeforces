#include<bits/stdc++.h>
using namespace std;
int a[100009],p[100009],s[100009];
main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        p[i] |= p[i-1] | a[i];
    }
    for(int i = n; i >= 1; i--){
        s[i] = s[i+1]|a[i];
    }
    int ans = 0, I = 1;
    for(int i =1 ; i <= n; i++){
        int x = (p[i-1] | s[i+1]);
        int y = (a[i] | x) - x;
        if(y > ans) ans = y, I = i;
    }
    cout << a[I] << " ";
    for(int i = 1; i <= n; i++)
     if(i != I) cout << a[i]<<" ";
     cout<<endl;
    return 0;
}