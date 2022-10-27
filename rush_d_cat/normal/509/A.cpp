#include <iostream>
using namespace std;
const int N=12;
int n,a[N][N];
int main() {
    for(int i=1;i<=10;i++)a[1][i]=a[i][1]=1;
    for(int i=2;i<=10;i++){
        for(int j=2;j<=10;j++){
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    cin>>n; cout<<a[n][n]<<endl;
}