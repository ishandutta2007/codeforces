#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.length();i++){
        if(a[i] == '='){
            //cout << a.length()-2 << " " << i-1 << " " << i+1 << endl;
            if(a.length() % 2 == 0 && (a.length()-2)/2 == i-1){
                cout << a;
            }else if(a.length()-2-i+1 == i+1){
                for(int i = 0; i < a.length()-1; i++){
                    if(i == 0){
                        cout << a[a.length()-1];
                    }
                    cout << a[i];
                }
            }else if(a.length()-2-i+1 == i-3){
                if(a[1] != '+'){
                    for(int i = 1; i<a.length();i++){
                        cout << a[i];
                        if(i == a.length()-1){
                            cout << a[0];
                        }
                    }
                }else{
                    for(int i = 0; i<a.length();i++){
                        if(i!=2){
                            cout << a[i];
                        }
                        if(i == a.length()-1){
                            cout << a[0];
                        }
                    }
                }
            }else{
                cout << "Impossible";
            }
        }
    }
}