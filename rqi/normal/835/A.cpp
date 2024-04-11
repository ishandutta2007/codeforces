#include <iostream>

using namespace std;

int main() {
    int a,b,c,d,e;
    int one, two;
    cin >> a >> b >> c >> d >>e;
    one = a*b + 2*d;
    two = a*c + 2*e;
    if(one > two){
        cout << "Second";
    }
    else if(one < two){
        cout << "First";
    }
    else cout << "Friendship";
}