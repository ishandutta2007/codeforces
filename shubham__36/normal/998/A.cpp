#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<2) {cout << -1 << endl;
    return 0;}
    int a[n],sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(n==2 && a[0]==a[1]){
        cout << -1 << endl;
    return 0;
    }
    if(a[0]*2!=sum){
        cout << "1" << endl;
        cout << "1" << endl;
    }
    else{
        cout << "2" << endl;
        cout << "1 2" << endl;
    }
    return 0;
}