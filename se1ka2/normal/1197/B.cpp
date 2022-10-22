#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200004];
    int lar = 0;
    int arglar = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > lar){
            lar = a[i];
            arglar = i;
        }
    }
    for(int i = arglar - 1; i >= 0; i--) if(a[i] >= a[i + 1]){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = arglar + 1; i < n; i++) if(a[i] >= a[i - 1]){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}