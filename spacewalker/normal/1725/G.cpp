#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)

int main() {
    int n;
    cin>>n;
    if (n == 1) {
        cout<<3<<"\n";return 0;
    }
    n +=2;n--;
    int grps = n/3;
    int base = grps*4;

    int rem = n%3;
    if (rem == 0) base+=1;
    if (rem == 1) base += 3;
    if (rem == 2) base += 4;
    cout<<base;
    

}