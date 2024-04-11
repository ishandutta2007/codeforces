#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    int counter = 1;
    int nonfunctional = 0;
    cin >> a;
    for(int i = 0; i < a.length()-1;i++){
        if(a[i] == a[i+1]){
            counter++;
        }else{
            if(counter % 2 == 0){
                nonfunctional++;
                counter = 1;
            }
        }
        //cout << counter;
        if(i == a.length()-2 && counter != 1 && counter % 2 == 0){
            nonfunctional++;
        }
    }
    cout << nonfunctional;
    
}