#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int n;
    int k;
    cin >> n >> k;
    cin >> a;
    bool t = false;
    for(int j = 0; j<k; j++){
        for(int i = 1; i<n;i++){
            if(t == true){
                t = false;
            }
            else if(a[i-1] == 'B' && a[i] == 'G'){
                a[i-1] = 'G';
                a[i] = 'B';
                t = true;
            }
        }
        t = false;
    }
    cout << a;
}