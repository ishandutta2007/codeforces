#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int counter2 = 0;
    for(int i = 0; i<n;i++){
        string a;
        cin >> a;
        int counter = 0;
        for(int j = 0; j<a.length();j++){
            if(a[j] == '4' || a[j] == '7'){
                counter++;
            }
        }
        if(counter <= k){
            counter2++;
        }
    }
    cout << counter2;
    return 0;
}