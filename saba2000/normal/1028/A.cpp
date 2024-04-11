#include<bits/stdc++.h>
using namespace std;
main(){
    int n, m;
    cin >> n >> m;
    int x1  = -1, x2 = -1, y1=-1, y2=-1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char k;
            cin >> k;
            if(k == 'B'){
                if(x1 == -1) x1 = i;
                if(y1 == -1) y1 = j;
                x2 = i;
                y2 = j;
            }
        }

    }
    cout<<(x1+x2)/2 <<" "<<(y1+y2)/2<<endl;
}