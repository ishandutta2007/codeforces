#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x;
    int found = 0;
    int candnum = 0;
    int candsgiv = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        candnum += x;
        if(candnum <=8){
            candsgiv += candnum;
            candnum = 0;
        }
        else {
            candnum -= 8;
            candsgiv +=8;
        }
        if(candsgiv >= k){
            cout << i+1;
            found = 1;
            break;
        }
    }
    if(found == 0){
        cout << -1;
    }
}