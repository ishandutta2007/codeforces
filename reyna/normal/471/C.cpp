#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int counter = 0;
    for(int i = 1; i < 1000000+1000;i++){
        if((n-(i*2))%3==0 && ((long long)i*(i-1))/2<=(n-(i*2))/3){
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}