#include <iostream> //scott this is just xor right
#include <cstdio> //steven idk
#include <string> //ray

using namespace std; //scott
string a, b; //steven

int main(){ //ray
cin >> a >> b; //scott
//int len = int(a.size());//steven
int len = a.length(); // ray

for (int i = 0; i < len; i++) { //scott
int ch = (a[i] - '0')  ^ (b[i] - '0'); //steven also .size() works too
cout << ch; //ray
}//scott
cout << endl; //steven

} //ray GG