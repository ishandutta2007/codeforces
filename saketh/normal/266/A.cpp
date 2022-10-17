#include<iostream>
using namespace std;

int N, a;
char p, t;

int main(){
    for(cin >> N; N; N--){
        cin >> t;
        a += t==p;
        p = t;
    }
    cout << a << endl;
}