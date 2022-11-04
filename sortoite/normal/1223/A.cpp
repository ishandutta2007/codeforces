#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        int m=0;
        if(n<4) m+=4-n, n=4;
        m+=n&1;
        cout<<m<<endl;
    }
    return 0;
}