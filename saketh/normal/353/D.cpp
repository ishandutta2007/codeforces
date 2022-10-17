#include<iostream>
using namespace std;

int A;
char g;

int main(){
    for(int c=1, p=1; cin >> g; c++){
        if(g=='M') continue;
        else if(g=='F'){
            if(c-p > A) A = c-p;
            else if(c-p) A++;
            p++;
        }
        else break;
    }
    cout << A << endl;
}