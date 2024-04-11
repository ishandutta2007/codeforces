#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int s = 1000000007;
    int min = 1000000007;
    int andis = 0;
    for(int i = 0; i < n;i++){
        int a;
        cin >> a;
        if(a == min){
            s = min;
        }
        if(a < min){
            min = a;
            andis = i+1;
        }
    }
    if(min == s){
        cout << "Still Rozdil" << endl;
        return 0;
    }
    cout << andis << endl;
    return 0;
}