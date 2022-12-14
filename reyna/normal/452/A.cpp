#include <iostream>
#include <string>
using namespace std;
string a[8];
int main(){
    a[0] = "vaporeon";
    a[1] = "jolteon";
    a[2] = "flareon";
    a[3] = "espeon";
    a[4] = "umbreon";
    a[5] = "leafeon";
    a[6] = "glaceon";
    a[7] = "sylveon";
    int n;
    cin >> n;
    string b;
    cin >> b;
    for(int i = 0; i < 8;i++){
        bool k = true;
        if(a[i].length() == b.length()){
            for(int j = 0; j < a[i].length(); j++){
                if(a[i][j] == b[j] || b[j] == '.'){
                    
                }else{
                    k = false;
                    break;
                }
            }
            if(k == true){
                cout << a[i] << endl;
                break;
            }
        }
    }
    return 0;
}