#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    char special = a[0][0];
    char special2 = a[0][1];
    if(special == special2){
        cout << "NO";
        return 0;
    }
//  cout << special << " " << special2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n;j++){
            if(i == j && a[i][j] == a[i][n-1-j] && a[i][j] == special){
                
            }else if(j == n-1-i && a[i][j] == a[i][n-1-j] && a[i][j] == special){
                
            }else if(i == j){
                cout << "NO";
                return 0;
            }else if(a[i][j] == special2){
                
            }else{
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}