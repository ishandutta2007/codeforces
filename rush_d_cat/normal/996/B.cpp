#include <iostream>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,a[N];
int main(){
    scanf("%d",&n);
    int bst=0,mn=2e9;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int k=(a[i]+1-i+n-1)/n;
        int t=k*n+i;
        if(t<mn){
            mn=t, bst=i;
        }
    }
    cout<<bst<<endl;
}