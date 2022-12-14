#include <iostream>
#include <string>
using namespace std;
bool distinct[26];
int main(){
    string a;
    cin >> a;
    int counter =0;
    for(int i = 0; i < a.length();i++){
        distinct[int(a[i])-'a'] = true;
    }
    for(int i = 0;i<26;i++){
        if(distinct[i] == true){
            counter++;
        }
    }
    if(counter % 2 == 0){
        cout << "CHAT WITH HER!";
    }else{
        cout << "IGNORE HIM!";
    }
}