#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int mine = min(m, n/k);
        int left = m - mine;
        int num = (left+k-2) / (k-1);
        cout<<mine - num<<endl;
    }
    return 0;
}