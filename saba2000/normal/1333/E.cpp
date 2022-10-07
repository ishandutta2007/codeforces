#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x[3][3] = {
    {1,2,6},{9,3,7},{4,5,8}
};
int ans[509][509];
main(){
    int n;
    cin >> n;
    if(n < 3){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ans[i][j] = n * n - 9 + x[i][j];
        }
    }
    int c = 1;
    for(int i = 3; i < n; i++){
        if(i % 2){
            for(int j = 0; j <= i; j++)
                ans[j][i] = c++;
            for(int j = i-1; j >= 0; j--)
                ans[i][j] = c++;
        }
        else{
            for(int j = 0; j <= i; j++)
                ans[i][j] = c++;
            for(int j = i-1; j >= 0; j--)
                ans[j][i] = c++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        cout<<ans[i][j]<<" ";
    cout<<endl;}
}
/*
1261
9372
4583
   4
*/