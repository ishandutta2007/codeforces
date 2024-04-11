#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 1;i <= (n*n)/2;i++){
        cout << i << " " << n*n+1-i;
        counter+= ((n*n)+1);
        if(counter == (n*(n*n+1))/2){
            cout << endl;
            counter = 0;
            continue;
        }
        cout << " ";
    }
}