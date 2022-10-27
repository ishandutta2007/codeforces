#include <iostream>

using namespace std;
int n,m;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    if(n<=m){
        for(int i=1;i<=n;i++) printf("GB");
        for(int i=1;i<=m-n;i++) printf("G");
    } else {
        for(int i=1;i<=m;i++) printf("BG");
        for(int i=1;i<=n-m;i++) printf("B");
    }
}