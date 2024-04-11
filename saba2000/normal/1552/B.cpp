#include<bits/stdc++.h>
using namespace std;
int r[50009][5];
bool C(int x, int y){
    int a = 0,b  = 0;
    for(int i = 0; i < 5; i++)
        if(r[x][i] < r[y][i])a++; else b++;
    return a > b;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        cin >>n;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 5; j++){
                cin >> r[i][j];
            }
        }
        int p = 1;
        for(int i = 2; i <= n; i++){
            if(C(i, p)) p = i;
        }
        int ok = 1;
        for(int i = 1; i <= n; i++){
            if(i != p && C(i, p)) ok = 0;
        }
        if(ok) cout<<p<<endl;
        else cout <<-1<<endl;

    }

}