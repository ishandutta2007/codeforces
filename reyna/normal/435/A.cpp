#include <iostream>
using namespace std;
int a[105];
int counter;
int main(){
    int n,m;
    int numberofbuses = 1;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        counter += a[i];
        if(counter > m){
            counter = a[i];
            numberofbuses++;
        }
    }
    cout << numberofbuses;
}