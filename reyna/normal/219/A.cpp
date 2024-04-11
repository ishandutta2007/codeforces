#include <iostream>
#include <string>
using namespace std;
int distinct[26];
int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b = "";
    for(int i = 0; i < a.length();i++){
//      cout << int(a[i])-'a';
        distinct[int(a[i])-int('a')]++;
    }
    for(int j = 0; j<n;j++){
        for(int i = 0; i < 26;i++){
            if(distinct[i] % n != 0){
                cout << -1;
                return 0;
            }else{
                for(int k = 0; k < distinct[i]/n;k++){
                    b += char(i+int('a'));
                }
            }
        }
    }
    cout << b;
    
}