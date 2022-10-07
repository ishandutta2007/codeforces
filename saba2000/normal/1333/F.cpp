#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[500009],g[500009];
main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j += i){
            if(f[j]) ans--,f[j] = 0;

        }
        ans++; f[i] = 1;
        g[i] = ans + i - 1;
    }
    int j = 1;
    for(int i = 2; i <= n; i++){
        while(i > g[j]) j++;
        printf("%d ", j - 1);
    }
    cout<<endl;
}
/*
1 2 3 4 5 6 7 8 9 10
*/