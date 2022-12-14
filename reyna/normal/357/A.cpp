#include <iostream>
using namespace std;
int c[100];
int main(){
    int m;
    cin >> m;
    int counter = 0;
    for(int i = 0; i < m; i++){
        cin >> c[i];
        counter += c[i];
    }
    int x,y;
    cin >> x >> y;
    bool k = false;
    int counter1 = 0;
    for(int i = 0; i < m; i++){
        counter1+=c[i];
        if((counter1) <= y && (counter1) >= x && (counter-counter1) <= y && (counter-counter1) >= x){
            cout << i+2 << endl;
            k = true;
            break;
        }
    }
    if(k == false){
        cout << 0 << endl;
    }
    return 0;
}