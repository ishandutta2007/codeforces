#include <iostream>

using namespace std;

int main()
{
    int x;
cin >> x;
cout << 6-x << endl;
int a[6] = {0};
string b[6] = {"Power","Time","Space","Soul","Reality","Mind"};
string com;
for(int i=0;i<x;i++){
    cin >> com;
    if(com[0] == 'p') a[0]=1;
    if(com[0] == 'g') a[1]=1;
    if(com[0] == 'b') a[2]=1;
    if(com[0] == 'o') a[3]=1;
    if(com[0] == 'r') a[4]=1;
    if(com[0] == 'y') a[5]=1;
}
for(int i=0;i<6;i++){
    if(a[i]==0) cout << b[i] << endl;
}
    return 0;
}