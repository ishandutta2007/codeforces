#include<iostream>
#include<cmath>
using namespace std;

int A, B;
int X, Y, Z;

int main(){
    cin >> A >> B;
    
    for(int c=1; c<=6; c++){
        int adist = abs(A - c);
        int bdist = abs(B - c);
        
        if(adist < bdist) X++;
        else if(adist == bdist) Y++;
        else Z++;
    }
    
    cout << X << " " << Y << " " << Z << endl;
    
    return 0;
}