#include<iostream>
#include <string>
using namespace std;
bool distinct[26];
int main(){
    int counter = 0;
    for(int i = 0; i < 1000;i++){
        string a;
        cin >> a;
        if(i == 0 && a[1] != '}' && a[2] != '}'){
            distinct[int(a[1])-'a'] = true;
        }else if(i == 0 && a[1] == '}'){
            cout << 0;
            return 0;
        }else if(i == 0 && a[2] == '}'){
            cout << 1;
            return 0;
        }else if(a[1] == '}'){
            distinct[int(a[0])-'a'] = true;
            break;
        }else{
            distinct[int(a[0])-'a'] = true;
        }
    }
    for(int i = 0; i < 26; i++){
        if(distinct[i] == true){
            counter++;
        }
    }
    cout << counter;
    
}