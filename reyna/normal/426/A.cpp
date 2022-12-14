#include <iostream>
using namespace std;
int main(){
    int n,s;
    int max = 0;
    int counter = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        counter += a;
        if(a > max){
            max = a;
        }
    }
    if(counter-max > s){
        cout << "NO";
        return 0;
    }else{
        cout << "YES";
        return 0;
    }
}