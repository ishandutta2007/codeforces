#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int main(){
    cin>>a>>b>>c;
    b-=1; c-=2;
    printf("%d", 3*min(a, min(b, c))+3);
}