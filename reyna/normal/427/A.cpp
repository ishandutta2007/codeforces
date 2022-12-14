#include <iostream>
using namespace std;
int Police;
int Untreated;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == -1 && Police == 0){
            Untreated++;
        }else if(a == -1 && Police != 0){
            Police--;
        }else if(a != -1){
            Police += a;
        }
    }
    cout << Untreated;
}