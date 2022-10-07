#include<bits/stdc++.h>
using namespace std;
int d[109][109];
main(){
    int L, R;
    cin >> L>> R;
    R -= L - 1;
    cout<<"YES"<<endl;
    for(int i = 21; i >= 1; i--){
        for(int j = i + 1; j <= 21; j++){
            d[i+1][j+1] = (1 << max(0, 20 - j));
        }
    }
    for(int i = 19; i >= 0; i--){
        if(R == (1<<i)) {
            for(int j = 0; j <= i; j++)
                d[1][22 - j] = (1<<(max(0, j-1)));
        } else
        if((1<<i) & R) d[1][22-i-1] = (R - (1<<i)), R -= (1<<i);
    }
    int m = 0;
    for(int i =1; i <= 22; i++){
        for(int j =i+1; j <= 22; j++){
            if(d[i][j]) m++;
        }
    }
    cout<<22<<" "<<m<<endl;
     for(int i =1; i <= 22; i++){
        for(int j =i+1; j <= 22; j++){
            int x = d[i][j];
            if(!x) continue;
            cout<<i<<" "<<j<<" ";
            if(i == 1) cout<<x+L-1<<endl;
            else cout << x<<endl;
        }
    }

}
//1 2 1 2