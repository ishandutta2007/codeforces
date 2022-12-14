#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int a1=(b*c)/g,a2=e*d,a3=f/h;
    if(a1 <= a2 && a1 <= a3){
        cout << a1/a;
        return 0;
    }
    if(a2 <= a1 && a2 <= a3){
        cout << a2/a;
        return 0;
    }
    cout << a3/a;
    return 0;
    
}