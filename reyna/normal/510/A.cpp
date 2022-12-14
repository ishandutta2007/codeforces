//In the name of God
#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int k = 0;
    for(int i = 0; i < n;i++){
        if(i % 2){
            if(k % 2)
                cout << '#';
            for(int j = 0; j < m-1;j++){
                cout << '.';
            }
            k++;
            if(k % 2)
                cout << '#';
            cout << endl;
        }else{
            for(int j = 0; j < m;j++)
                cout << '#';
            cout << endl;
        }
    }
    return 0;
}