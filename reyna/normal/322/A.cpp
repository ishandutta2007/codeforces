#include <iostream>
using namespace std;
int main(){
    int boys,girls;
    cin >> boys >> girls;
    cout << boys + girls -1;
    int ptr1 = 1;
    int ptr2 = 1;
    cout << endl;
    while(1){
        if(ptr1 <= boys){
            cout << ptr1 << " " << ptr2;
            ptr1++;
        }else if(ptr2 < girls){
            ptr2++;
            cout << ptr1-1 << " " << ptr2;
        }else{
            break;
        }
        cout << endl;
    }
}