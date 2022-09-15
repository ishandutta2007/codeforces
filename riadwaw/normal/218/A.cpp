#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int N = 1000;

int main() {
    auto n = 0,k = 0;
    cin>>n>>k;

    auto a = new int[2*n+1];

    for(int i=0;i<=2*n;i++) {
        cin>>a[i];
    }

    for(int i=0;i<=2*n;i++) {
        if(k && i%2==1 && a[i]-a[i-1]>1 && a[i]-a[i+1]>1) {
            a[i]--;
            k--;
        }
        cout<<a[i]<<' ';
    }
    return 0;
}