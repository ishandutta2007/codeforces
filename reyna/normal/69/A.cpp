#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int c1=0,c2=0,c3=0;
    for(int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        c1+=a;
        c2+=b;
        c3+=c;
    }
    if(c1 == 0 && c2 == 0 && c3==0){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}