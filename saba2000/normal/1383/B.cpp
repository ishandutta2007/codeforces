#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100009];
main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int s = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
            s ^= a[i];
        }


        if(s == 0){
            cout <<"DRAW"<<endl;
            continue;
        }
        int u = 0;
        for(int j = 0; j < 30; j++)
            if((1<<j) & s) u = j;
        int A = 0, B = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] & (1<<u)) A++;
            else B++;
        }
        if(B % 2 == 0) cout << (A / 2 % 2 == 0 ?"WIN" : "LOSE") << endl;

        else cout<<"WIN"<<endl;
    }

}
/*
1 1 1 0

*/