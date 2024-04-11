#include<bits/stdc++.h>
using namespace std;
main(){
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int a[3] ={x1,x2,x3};
    sort(a,a+3);

    cout<<max({y1,y2,y3})-min({y1,y2,y3})+a[2] - a[0] + 1 << endl;
        for(int i = min({y1,y2,y3}); i <= max({y1,y2,y3}); i++){
            cout<<a[1] <<" "<<i<<endl;
        }
    for(int i = min(x1,a[1]); i <= max(x1,a[1]); i++){
        if(i != a[1]) cout << i <<" "<<y1<<endl;
    }
    for(int i = min(x2,a[1]); i <= max(x2,a[1]); i++){
        if(i != a[1]) cout << i <<" "<<y2<<endl;
    }
    for(int i = min(x3,a[1]); i <= max(x3,a[1]); i++){
        if(i != a[1]) cout << i <<" "<<y3<<endl;
    }

}