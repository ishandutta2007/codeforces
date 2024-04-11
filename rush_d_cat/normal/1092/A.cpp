#include <iostream>
#include <algorithm>
using namespace std;
const int N=200000+10;
typedef long long LL;
int t,n,k;
int main() {
    cin>>t;
    while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        printf("%c", 'a'+i%k);
    }printf("\n");
    }
}