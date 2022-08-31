#include <iostream>

using namespace std;

bool searc(int k,int b[],int m){
    for(int i=0;i<m;i++){
        if(k==b[i]) return true;
    }
    return false;
}

int main()
{
    int n,m,k;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        k=a[i];
        if(searc(k,b,m)) cout << k << " ";
    }
    return 0;
}