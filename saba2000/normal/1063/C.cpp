#include<bits/stdc++.h>
using namespace std;
int ask(int x, int y){
    cout<<x<<" "<<y<<endl;
    string s;
    cin >> s;
    if(s[0] == 'b') return 1;
    return 0;
}
main(){
    int n;
    cin >> n;
    int l = 1, r =1e9;
    int f = ask(0,1);
    for(int i = 1; i < n; i++){
        int mid = (l + r)/2;
        int x = ask(mid,1);
        if(x == f) {
            l = mid+1;
        }

            else r = mid - 1;

    }
    if(l == r + 1) cout << r<<" "<<2<<" "<<l<<" "<<0<<endl;
    else 
    cout<< l<<" "<<0 <<" "<<l<<" "<<1<<endl;
}