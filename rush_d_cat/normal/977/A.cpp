#include <iostream>
using namespace std;
int n,k;
int main() {
    cin>>n>>k;
    for(int i=1;i<=k;i++) {
        if(n%10) n--;
        else n/=10;
    }
    cout<<n<<endl;
}