#include <iostream>
using namespace std;
int home[100];
int guest[100];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        home[a-1]++;
        guest[b-1]++;
    }
    int counter =0;
    for(int i = 0; i < 100; i++){
        counter += guest[i]*home[i];
    }
    cout << counter;
}