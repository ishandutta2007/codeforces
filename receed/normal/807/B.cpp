#include <bits/stdc++.h>

using namespace std;


int main(){
    int p, x, y,c;
    bool f;
    cin>>p>>x>>y;
    x-=500000;
    for(int i = -10000; i <100000; i++, x+=50){
        if(x<y)
            continue;
        f = 0;
        c = (x/50)%475;
        for(int j = 0;j<25;j++){
            c = (c*96 + 42) % 475;
            if(c+26==p)
                f=1;
        }
        if(f){
            if(i<=0)
                cout<<0;
            else
                cout<<(i+1)/2;
            break;
        }
    }
    return 0;
}