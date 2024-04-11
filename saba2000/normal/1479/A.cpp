#include<bits/stdc++.h>
using namespace std;
int ask(int x){
    cout << "? " <<x<<endl;
    int y;
    cin>>y;
    return y;
}
main(){
    srand(time(0));
    int n;
    cin >> n;
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r)/2;
        if(ask(mid) < ask(mid + 1)) r = mid;
        else l = mid + 1;
    }
     cout<<"! "<<l<<endl;

}
// n-1