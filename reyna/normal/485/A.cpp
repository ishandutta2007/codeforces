#include <iostream>
using namespace std;
bool Vis[123456];
int main(){
    int x,m;
    cin >> x >> m;
    x%=m;
    while((x*2)%m){
        x*=2;
        x%=m;
        if(Vis[x]){
            cout << "No" << endl;
            return 0;
        }
        Vis[x] = true;
    }
    cout << "Yes" << endl;
    return 0;
}